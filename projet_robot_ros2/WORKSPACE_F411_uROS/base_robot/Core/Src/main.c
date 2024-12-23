#include "main.h"
#include "motorCommand.h"
#include "quadEncoder.h"
#include "captDistIR.h"
#include "VL53L0X.h"
#include "groveLCD.h"

#define ARRAY_LEN 100
#define SAMPLING_PERIOD_ms 5
#define FIND_MOTOR_INIT_POS 0

//################################################
#define EX1 1
#define EX2 2
#define EX3 3

#define SYNCHRO_EX EX1
//################################################
//################################################
// PARAMETRE A MODIFIER EN FONCTION DU N° ROBOT
#define ROS_DOMAIN_ID 11
//################################################
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern DMA_HandleTypeDef hdma_usart2_tx;

extern I2C_HandleTypeDef hi2c1;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 3000 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};


xSemaphoreHandle xSemaphore = NULL;
xQueueHandle qh = NULL;
SemaphoreHandle_t messageSemaphore;

TaskHandle_t randomTaskHandle = NULL;
TaskHandle_t manualTaskHandle = NULL;
TaskHandle_t trackingTaskHandle= NULL;

static TaskHandle_t TaskModeHandle = NULL;

struct AMessage
{
	char command;
	int data;
};


void SystemClock_Config(void);
void microros_task(void *argument);
uint16_t mes_vl53=0;

int mode_courant=1;
int Left_first_index_reached = 0;
int Right_first_index_reached = 0;

//========================================================================
#if SYNCHRO_EX == EX1

char current_message[18];
int speed_consigne = 130;

int tracking_move=2;

static void manual_mode(void *pvParameters) {
	for(;;){
		 if (tracking_move==3) { // Obstacle à gauche
		            // Tourner à droite
		            motorLeft_SetDuty(speed_consigne); // Moteur gauche rapide
		            motorRight_SetDuty(100); // Moteur droit lent
		            vTaskDelay(pdMS_TO_TICKS(500)); // Tourner pendant 0.5s


		        } else if (tracking_move==4) { // Obstacle à droite
		            // Tourner à gauche
		            motorLeft_SetDuty(100); // Moteur gauche lent
		            motorRight_SetDuty(speed_consigne); // Moteur droit rapide
		            vTaskDelay(pdMS_TO_TICKS(500)); // Tourner pendant 0.5s
		        } else if (tracking_move==2) { // Obstacle à l'arrière
		            // Avancer pour éviter l'obstacle
		            motorLeft_SetDuty(speed_consigne);
		            motorRight_SetDuty(speed_consigne);
		            vTaskDelay(pdMS_TO_TICKS(500)); // Avancer pendant 0.5s
		        } else if (tracking_move==1) {
		            // Pas d'obstacle, mode aléatoire
		            motorLeft_SetDuty(200 - speed_consigne);
		            motorRight_SetDuty(200 -speed_consigne);
		            vTaskDelay(pdMS_TO_TICKS(1000)); // Changer de vitesse toutes les 1 seconde
		        }else  if (tracking_move==5){
		            // Pas d'obstacle, mode aléatoire
		            motorLeft_SetDuty(100);
		            motorRight_SetDuty(100);
		            vTaskDelay(pdMS_TO_TICKS(1000)); // Changer de vitesse toutes les 1 seconde
		        }
		 vTaskDelay(5);
	}


}
int front_capt[2];
uint16_t back_capt;

static void random_mode(void *pvParameters) {

    int speedLeft, speedRight;

    for (;;) {
        // Lire les capteurs
    	int front_distance[2];
    	uint16_t back_distance;
        captDistIR_Get(front_distance);  // Capteurs avant
        back_distance = VL53L0X_readRangeContinuousMillimeters();  // Capteur arrière
        mes_vl53 = back_distance;
        // Vérifier les obstacles
        if (front_distance[1] > 1000) { // Obstacle à gauche
            // Tourner à droite
            motorLeft_SetDuty(speed_consigne); // Moteur gauche rapide
            motorRight_SetDuty(100); // Moteur droit lent
           // strcpy(current_message, "Obstacle Gauche!");
            vTaskDelay(pdMS_TO_TICKS(500)); // Tourner pendant 0.5s
        } else if (front_distance[0] > 1000) { // Obstacle à droite
            // Tourner à gauche
            motorLeft_SetDuty(100); // Moteur gauche lent
            motorRight_SetDuty(speed_consigne); // Moteur droit rapide
           // strcpy(current_message, "Obstacle Droite!");
            vTaskDelay(pdMS_TO_TICKS(500)); // Tourner pendant 0.5s
        } else if (back_distance < 200) { // Obstacle à droite
            // Tourner à gauche
            motorLeft_SetDuty(100); // Moteur gauche lent
            motorRight_SetDuty(100); // Moteur droit rapide
           // strcpy(current_message, "Obstacle Droite!");
            vTaskDelay(pdMS_TO_TICKS(500)); // Tourner pendant 0.5s
        }  else {
            motorLeft_SetDuty(speed_consigne);
            motorRight_SetDuty(speed_consigne);
            vTaskDelay(pdMS_TO_TICKS(1000)); // Changer de vitesse toutes les 1 seconde
        }
    }
}

static void lcd_print(void *pvParameters) {
    static char previous_lcd_message[16] = "";
    groveLCD_begin(16, 2, 0);
    groveLCD_display();

    for (;;) {
        if (strcmp(previous_lcd_message, current_message) != 0) {
            groveLCD_setCursor(0, 0); // Positionne le curseur
            groveLCD_term_printf("%s", current_message);  // Affiche le message
            // Sauvegarde le message actuel
            strcpy(previous_lcd_message, current_message);
        }

        // Pause pour limiter les mises à jour de l'écran
        vTaskDelay(pdMS_TO_TICKS(200));  // Mise à jour toutes les 100 ms
    }
}

static void task_A(void *pvParameters)
{

	for (;;)
	{
		  vTaskDelay(5);
	}
}

static void task_B(void *pvParameters)
{
int i=0;

for (;;)
	{
		i++;
		vTaskDelay(1);
	}
}

char dirTracking[100];
static void track_mode(void *pvParameters) {

	for(;;){
		 if (strcmp(dirTracking, "right")==0) { // Obstacle à gauche
		            // Tourner à droite un peu et attendre un autre mouvement
		            motorLeft_SetDuty(speed_consigne);
		            motorRight_SetDuty(100); // Moteur droit lent
		            vTaskDelay(pdMS_TO_TICKS(500)); // Tourner pendant 0.5s
		            motorLeft_SetDuty(100); // Moteur gauche rapide
		            motorRight_SetDuty(100);

		        } else if (strcmp(dirTracking, "left")==0) { // Obstacle à droite
		            // Tourner à gauche un peu et attendre un autre mouvement
		            motorLeft_SetDuty(100); // Moteur gauche lent
		            motorRight_SetDuty(speed_consigne); // Moteur droit rapide
		            vTaskDelay(pdMS_TO_TICKS(500)); // Tourner pendant 0.5s
		            motorLeft_SetDuty(100); // Moteur gauche rapide
		            motorRight_SetDuty(100);

		        } else { // Forward
		            // Avancer
		            motorLeft_SetDuty(speed_consigne);
		            motorRight_SetDuty(speed_consigne);
		            vTaskDelay(pdMS_TO_TICKS(500)); // Avancer pendant 0.5s
		            motorLeft_SetDuty(100); // Moteur gauche rapide
		            motorRight_SetDuty(100);
		        }
		 vTaskDelay(5);
	}

}


static void send_data(void *pvParameters) {

	for(;;){
	captDistIR_Get(front_capt);
	back_capt = VL53L0X_readRangeContinuousMillimeters();
	vTaskDelay(5);
	}

}

void change_mode(void) {
    if (mode_courant == 0) {
        vTaskSuspend(manualTaskHandle);
        vTaskSuspend(trackingTaskHandle);
        strcpy(current_message, "random");
        vTaskResume(randomTaskHandle);
    } else if (mode_courant == 1) {
        vTaskSuspend(randomTaskHandle);
        vTaskSuspend(trackingTaskHandle);
        strcpy(current_message, "manual");
        vTaskResume(manualTaskHandle);
    } else if (mode_courant==2){
        vTaskSuspend(randomTaskHandle);
        vTaskSuspend(manualTaskHandle);
        strcpy(current_message, "tracking");
        vTaskResume(trackingTaskHandle);
    }
}

static void task_E_echantillonage( void *pvParameters )
{
	static int state = 1;
	for (;;)
	{
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, state);
	    state = !state;
		vTaskDelay(SAMPLING_PERIOD_ms);
	}
}

//========================================================
#elif SYNCHRO_EX == EX2

static void task_C( void *pvParameters )
{
	for (;;)
	{
		 printf("TASK C \n\r");
		xSemaphoreTake( xSemaphore, portMAX_DELAY );
	}
}

static void task_D( void *pvParameters )
{
	for (;;)
	{
		 printf("TASK D \n\r");
		xSemaphoreGive( xSemaphore );
	}
}

//========================================================
#elif SYNCHRO_EX == EX3

static void task_E( void *pvParameters )
{
	struct AMessage pxMessage;
	pxMessage.command='a';
	pxMessage.data=10;
	vTaskDelay(1000);
	for (;;)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
	    printf("TASK E \r\n");
		xQueueSend( qh, ( void * ) &pxMessage,  portMAX_DELAY );
		xSemaphoreTake( xSemaphore, portMAX_DELAY );

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
		vTaskDelay(SAMPLING_PERIOD_ms);
	}
}

static void task_F(void *pvParameters)
{
	struct AMessage pxRxedMessage;

	for (;;)
	{
		xQueueReceive( qh,  &( pxRxedMessage ) , portMAX_DELAY );
		 printf("TASK F \r\n");
		xSemaphoreGive( xSemaphore );
	}
}
#endif

//

//=========================================================================
int main(void)
{
  int ret=0;

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();

  motorCommand_Init();
  quadEncoder_Init();
  captDistIR_Init();

  HAL_Delay(500);

  // Affichage via UART2 sur Terminal série $ minicom -D /dev/ttyACM0
  printf("hello\r\n"); // REM : ne pas oublier le \n

  VL53L0X_init();

  ret = VL53L0X_validateInterface();
  if(ret ==0)
  {
	  printf("VL53L0X OK\r\n");
  }


  else
  {
	  printf("!! PROBLEME VL53L0X !!\r\n");
  }
  VL53L0X_startContinuous(0);

  int a, b;


  groveLCD_begin(16,2,0); // !! cette fonction prend du temps
  HAL_Delay(100);
  groveLCD_display();
  a=5; b=2;
  groveLCD_term_printf("%d+%d=%d",a,b,a+b);
  groveLCD_setCursor(0,0);
  groveLCD_term_printf("hello");


  HAL_Delay(50);

#if FIND_MOTOR_INIT_POS

  int16_t speed=0;
// RECHERCHE DE LA POSITION INITIALE ( 1er signal 'index' du capteur )
// Evite une erreur pour une mesure de vitesse 
	Left_first_index_reached = 0;
	 while( Left_first_index_reached != 1 )
	 {
		motorLeft_SetDuty(130);
		HAL_Delay(SAMPLING_PERIOD_ms);
		speed = quadEncoder_GetSpeedL();
	 }

	Right_first_index_reached = 0;
	 while( Right_first_index_reached != 1 )
	 {
		motorRight_SetDuty(130);printf("Received speed command: %d\n", speed_consigne);
		HAL_Delay(SAMPLING_PERIOD_ms);
		speed = quadEncoder_GetSpeedR();
	 }

	 motorLeft_SetDuty(100);
	 motorRight_SetDuty(100);
	 HAL_Delay(200);

	 speed = quadEncoder_GetSpeedL();
	 speed = quadEncoder_GetSpeedR;
#endif

  osKernelInitialize();

  messageSemaphore = xSemaphoreCreateMutex();
  if (messageSemaphore == NULL) {
      printf("Failed to create semaphore for message synchronization\n");
  }

  xTaskCreate( microros_task, ( const portCHAR * ) "microros_task", 3000 /* stack size */, NULL,  24, NULL );
  xTaskCreate(lcd_print, "LCD", 128, NULL, 5, NULL);
  xTaskCreate(send_data, "Send data", 128, NULL, 6, NULL);
  //xTaskCreate(task_E_echantillonage, "Send data", 128, NULL, 7, NULL);

  xTaskCreate(random_mode, "Random Mode", 128, NULL, 11, &randomTaskHandle);
  xTaskCreate(manual_mode, "Manual Mode", 128, NULL, 12, &manualTaskHandle);
  xTaskCreate(track_mode, "Tracking Mode", 128, NULL, 13, &trackingTaskHandle);


#if SYNCHRO_EX == EX1
	//xTaskCreate( task_A, ( const portCHAR * ) "task A", 128 /* stack size */, NULL, 26, NULL );
//	xTaskCreate( task_B, ( const portCHAR * ) "task B", 128 /* stack size */, NULL, 25, NULL );
#elif SYNCHRO_EX == EX2
	xTaskCreate( task_C, ( signed portCHAR * ) "task C", 128 /* stack size */, NULL, 28, NULL );
	xTaskCreate( task_D, ( signed portCHAR * ) "task D", 128 /* stack size */, NULL, 27, NULL );
#elif SYNCHRO_EX == EX3
	xTaskCreate( task_E, nt speedRight, errRight;
    float upRight;
    static float uiRight = 0.0;

    for (;;)
    {
        // Obtenir la vitesse actuelle de la roue droite
        speedRight = quadEncoder_GetSpeedR();

        // Calcul de l'

        str_msg.data.data = (char * ) malloc(ARRAY_LEN * sizeof(char));
        str_msg.data.size = 0;
        str_msg.data.capacity = ARRAY_LEN;
erreur par rapport à la consigne
        errRight = targetSpeedRight - speedRight;

        // Correction proportionnelle et intégrale
        upRight = Kp * errRight;
        uiRight += Ki * errRight;
( signed portCHAR * ) "task E", 128 /* stack size */, NULL, 30, NULL );
	xTaskCreate( task_F, ( signed portCHAR * ) "task F", 128 /* stack size */, NULL, 29, NULL );
#endif

	vSemaphoreCreateBinary(xSemaphore);
	xSemaphoreTake( xSemaphore, portMAX_DELAY );

	qh = xQueueCreate( 1, sizeof(struct AMessage ) );

  osKernelStart();

  while (1)
  {


  }

}

//=========================================================================
bool cubemx_transport_open(struct uxrCustomTransport * transport);
bool cubemx_transport_close(struct uxrCustomTransport * transport);
size_t cubemx_transport_write(struct uxrCustomTransport* transport, const uint8_t * buf, size_t len, uint8_t * err);
size_t cubemx_transport_read(struct uxrCustomTransport* transport, uint8_t* buf, size_t len, int timeout, uint8_t* err);

void * microros_allocate(size_t size, void * state);
void microros_deallocate(void * pointer, void * state);
void * microros_reallocate(void * pointer, size_t size, void * state);
void * microros_zero_allocate(size_t number_of_elements, size_t size_of_element, void * state);


void subscription_callback(const void *msgin) {
    const std_msgs__msg__String *msg = (const std_msgs__msg__String *)msgin;
    if (msg && msg->data.data) {
        char *data = msg->data.data;
        int mode = 0, speed = 0, direction = 0;

        char *token = strtok(data, ";");
        if (token) mode = atoi(token);
        if ((token = strtok(NULL, ";"))) speed = atoi(token);
        if ((token = strtok(NULL, ";"))) direction = atoi(token);

    	  mode_courant=mode;
          speed_consigne=speed;
          tracking_move=direction;
          change_mode();

    } else {
        printf("Received NULL message or data\n");
    }
}

void Tracking_subscription_callback(const void * msgin){

    const std_msgs__msg__String *msg = (const std_msgs__msg__String *)msgin;

    // Ensure msg and msg->data.data are valid
    if (msg && msg->data.data) {
        strcpy(dirTracking, msg->data.data);
    } else {
        printf("Received NULL message or data\n\r");
    }
}


void microros_task(void *argument)
{
  rmw_uros_set_custom_transport( true, (void *) &huart1, cubemx_transport_open,  cubemx_transport_close,  cubemx_transport_write, cubemx_transport_read);

  rcl_allocator_t freeRTOS_allocator = rcutils_get_zero_initialized_allocator();
  freeRTOS_allocator.allocate = microros_allocate;
  freeRTOS_allocator.deallocate = microros_deallocate;
  freeRTOS_allocator.reallocate = microros_reallocate;
  freeRTOS_allocator.zero_allocate =  microros_zero_allocate;

  if (!rcutils_set_default_allocator(&freeRTOS_allocator)) {
      printf("Error on default allocators (line %d)\n", __LINE__);
  }

  // micro-ROS app
  rclc_support_t support;
  rcl_allocator_t allocator;
  allocator = rcl_get_default_allocator();

  // create node
  rcl_node_t node;
  rcl_node_options_t node_ops = rcl_node_get_default_options();
  rcl_init_options_t init_options = rcl_get_zero_initialized_init_options();
  rcl_init_options_init(&init_options, allocator);
  rcl_init_options_set_domain_id(&init_options, ROS_DOMAIN_ID);

  rclc_support_init_with_options(&support, 0, NULL, &init_options, &allocator);
  rclc_node_init_default(&node, "STM32_Node","", &support);

  // create publisher
  rcl_publisher_t publisher;
 std_msgs__msg__String sensor_dist_back_msg;
 rclc_publisher_init_default(&publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),"/sensor/dist_back");

  // create subscriber
  rcl_subscription_t subscriber; //Move
  std_msgs__msg__String str_msg;
  rclc_subscription_init_default(&subscriber,&node,ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),"/command/move");

  // create subscriber
  rcl_subscription_t tracking_subscriber; //Tracking
  std_msgs__msg__String tracking_str_msg;
  rclc_subscription_init_default(&tracking_subscriber,&node,ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),"/command/tracking");

  // Add subscription to the executor
  rclc_executor_t executor;
  rclc_executor_init(&executor, &support.context, 3, &allocator); // ! 'NUMBER OF HANDLES' A MODIFIER EN FONCTION DU NOMBRE DE TOPICS
  rclc_executor_add_subscription(&executor, &subscriber, &str_msg, &subscription_callback, ON_NEW_DATA);
  rclc_executor_add_subscription(&executor, &tracking_subscriber, &tracking_str_msg, &Tracking_subscription_callback, ON_NEW_DATA);



  str_msg.data.data = (char * ) malloc(ARRAY_LEN * sizeof(char));
  str_msg.data.size = 0;
  str_msg.data.capacity = ARRAY_LEN;


  tracking_str_msg.data.data = (char * ) malloc(ARRAY_LEN * sizeof(char));
  tracking_str_msg.data.size = 0;
  tracking_str_msg.data.capacity = ARRAY_LEN;

  sensor_dist_back_msg.data.data = (char * ) malloc(ARRAY_LEN * sizeof(char));
  sensor_dist_back_msg.data.size = 0;
  sensor_dist_back_msg.data.capacity = ARRAY_LEN;

  for(;;)
  {
	  sprintf(str_msg.data.data, "%d;%d;%d;%d", (int32_t)back_capt,(int32_t)front_capt[0],(int32_t)front_capt[1],(int16_t)abs(quadEncoder_GetSpeedR()));
	  str_msg.data.size = strlen(str_msg.data.data);

      rcl_ret_t ret = rcl_publish(&publisher, &str_msg, NULL);

		if (ret != RCL_RET_OK)
		{
		  printf("Error publishing (line %d)\n\r", __LINE__);
		}
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(10));
    osDelay(10);
  }
}
//=========================================================================
/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM4)
  {
    HAL_IncTick();
  }
}
//=========================================================================
void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {}
}
//=========================================================================
#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
