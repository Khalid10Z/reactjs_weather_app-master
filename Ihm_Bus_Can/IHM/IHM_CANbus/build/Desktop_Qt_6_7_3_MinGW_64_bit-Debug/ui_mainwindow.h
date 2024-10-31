/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "objectgl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QGroupBox *groupBox_4;
    QLabel *lblVLValue_press;
    QLabel *lblVLValue_anemo;
    QLCDNumber *lcdNumber_press;
    QLCDNumber *lcdNumber_anemo;
    QLabel *lblVLValue_press_2;
    QLabel *lblVLValue_anemo_2;
    QSlider *horizontalSlider_vit;
    QLabel *lblVLValue_press_5;
    QLCDNumber *lcdNumber_hum;
    QLabel *lblVLValue_press_6;
    QCheckBox *checkBox_led;
    QLabel *lblVLValue_press_3;
    QLabel *lblVLValue_press_7;
    QLCDNumber *lcdNumber_temp;
    QLabel *lblVLValue_press_8;
    QPushButton *pushButton_update;
    QCheckBox *checkBox_vit_vent;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *lblMPAccX;
    QLabel *lblMPAccY;
    QLabel *label_5;
    QLabel *lblMPAccZ;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *lblMPGyrX;
    QLabel *lblMPGyrY;
    QLabel *lblMPGyrZ;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *lblMPphi;
    QLabel *lblMPpsi;
    QLabel *lblMPtheta;
    ObjectOpenGL *openGLWidget;
    QGroupBox *groupBox_5;
    QLCDNumber *lcdNumber_dist;
    QLCDNumber *lcdNumber_lumi;
    QLabel *lblVLValue_press_4;
    QLabel *lblVLValue_anemo_4;
    QRadioButton *radioButton_dist;
    QRadioButton *radioButton_lumi;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(632, 553);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 10, 611, 161));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(233, 185, 110, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 240, 215, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(244, 212, 162, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(116, 92, 55, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(155, 123, 73, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(244, 220, 182, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush10(QColor(0, 0, 0, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush11(QColor(0, 0, 0, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        groupBox_4->setPalette(palette);
        lblVLValue_press = new QLabel(groupBox_4);
        lblVLValue_press->setObjectName("lblVLValue_press");
        lblVLValue_press->setGeometry(QRect(10, 20, 71, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("DejaVu Sans Mono")});
        font.setBold(true);
        font.setItalic(false);
        lblVLValue_press->setFont(font);
        lblVLValue_press->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_press->setWordWrap(true);
        lblVLValue_anemo = new QLabel(groupBox_4);
        lblVLValue_anemo->setObjectName("lblVLValue_anemo");
        lblVLValue_anemo->setGeometry(QRect(160, 20, 131, 21));
        lblVLValue_anemo->setFont(font);
        lblVLValue_anemo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_anemo->setWordWrap(true);
        lcdNumber_press = new QLCDNumber(groupBox_4);
        lcdNumber_press->setObjectName("lcdNumber_press");
        lcdNumber_press->setGeometry(QRect(10, 40, 91, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush12(QColor(252, 175, 62, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush12);
        QBrush brush13(QColor(255, 227, 186, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush13);
        QBrush brush14(QColor(253, 201, 124, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        QBrush brush15(QColor(126, 87, 31, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush15);
        QBrush brush16(QColor(168, 117, 41, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush17(QColor(253, 215, 158, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush18(QColor(0, 0, 0, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush18);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush19(QColor(0, 0, 0, 128));
        brush19.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush19);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush20(QColor(0, 0, 0, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush20);
#endif
        lcdNumber_press->setPalette(palette1);
        lcdNumber_press->setFrameShadow(QFrame::Plain);
        lcdNumber_press->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_anemo = new QLCDNumber(groupBox_4);
        lcdNumber_anemo->setObjectName("lcdNumber_anemo");
        lcdNumber_anemo->setGeometry(QRect(160, 40, 81, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush13);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush15);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush21(QColor(252, 175, 62, 128));
        brush21.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush21);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush22(QColor(252, 175, 62, 128));
        brush22.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush22);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush23(QColor(252, 175, 62, 128));
        brush23.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush23);
#endif
        lcdNumber_anemo->setPalette(palette2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lohit Bengali")});
        font1.setBold(false);
        lcdNumber_anemo->setFont(font1);
        lcdNumber_anemo->setLayoutDirection(Qt::LeftToRight);
        lcdNumber_anemo->setFrameShadow(QFrame::Plain);
        lcdNumber_anemo->setSegmentStyle(QLCDNumber::Flat);
        lblVLValue_press_2 = new QLabel(groupBox_4);
        lblVLValue_press_2->setObjectName("lblVLValue_press_2");
        lblVLValue_press_2->setGeometry(QRect(110, 50, 31, 21));
        lblVLValue_press_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_press_2->setWordWrap(true);
        lblVLValue_anemo_2 = new QLabel(groupBox_4);
        lblVLValue_anemo_2->setObjectName("lblVLValue_anemo_2");
        lblVLValue_anemo_2->setGeometry(QRect(260, 50, 41, 21));
        lblVLValue_anemo_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_anemo_2->setWordWrap(true);
        horizontalSlider_vit = new QSlider(groupBox_4);
        horizontalSlider_vit->setObjectName("horizontalSlider_vit");
        horizontalSlider_vit->setGeometry(QRect(10, 130, 501, 22));
        horizontalSlider_vit->setMinimum(-100);
        horizontalSlider_vit->setMaximum(100);
        horizontalSlider_vit->setOrientation(Qt::Horizontal);
        horizontalSlider_vit->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_vit->setTickInterval(0);
        lblVLValue_press_5 = new QLabel(groupBox_4);
        lblVLValue_press_5->setObjectName("lblVLValue_press_5");
        lblVLValue_press_5->setGeometry(QRect(420, 50, 31, 21));
        lblVLValue_press_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_press_5->setWordWrap(true);
        lcdNumber_hum = new QLCDNumber(groupBox_4);
        lcdNumber_hum->setObjectName("lcdNumber_hum");
        lcdNumber_hum->setGeometry(QRect(320, 40, 91, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush13);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush15);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush24(QColor(0, 0, 0, 128));
        brush24.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush24);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush25(QColor(0, 0, 0, 128));
        brush25.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush25);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush26(QColor(0, 0, 0, 128));
        brush26.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        lcdNumber_hum->setPalette(palette3);
        lcdNumber_hum->setFrameShadow(QFrame::Plain);
        lcdNumber_hum->setSegmentStyle(QLCDNumber::Flat);
        lblVLValue_press_6 = new QLabel(groupBox_4);
        lblVLValue_press_6->setObjectName("lblVLValue_press_6");
        lblVLValue_press_6->setGeometry(QRect(320, 20, 71, 21));
        lblVLValue_press_6->setFont(font);
        lblVLValue_press_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_press_6->setWordWrap(true);
        checkBox_led = new QCheckBox(groupBox_4);
        checkBox_led->setObjectName("checkBox_led");
        checkBox_led->setGeometry(QRect(440, 100, 51, 20));
        lblVLValue_press_3 = new QLabel(groupBox_4);
        lblVLValue_press_3->setObjectName("lblVLValue_press_3");
        lblVLValue_press_3->setGeometry(QRect(10, 80, 71, 21));
        lblVLValue_press_3->setFont(font);
        lblVLValue_press_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_press_3->setWordWrap(true);
        lblVLValue_press_7 = new QLabel(groupBox_4);
        lblVLValue_press_7->setObjectName("lblVLValue_press_7");
        lblVLValue_press_7->setGeometry(QRect(570, 50, 71, 21));
        lblVLValue_press_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_press_7->setWordWrap(true);
        lcdNumber_temp = new QLCDNumber(groupBox_4);
        lcdNumber_temp->setObjectName("lcdNumber_temp");
        lcdNumber_temp->setGeometry(QRect(470, 40, 91, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush13);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush15);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush27(QColor(0, 0, 0, 128));
        brush27.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush27);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush28(QColor(0, 0, 0, 128));
        brush28.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush28);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush29(QColor(0, 0, 0, 128));
        brush29.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush29);
#endif
        lcdNumber_temp->setPalette(palette4);
        lcdNumber_temp->setFrameShadow(QFrame::Plain);
        lcdNumber_temp->setSegmentStyle(QLCDNumber::Flat);
        lblVLValue_press_8 = new QLabel(groupBox_4);
        lblVLValue_press_8->setObjectName("lblVLValue_press_8");
        lblVLValue_press_8->setGeometry(QRect(470, 20, 101, 21));
        lblVLValue_press_8->setFont(font);
        lblVLValue_press_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_press_8->setWordWrap(true);
        pushButton_update = new QPushButton(groupBox_4);
        pushButton_update->setObjectName("pushButton_update");
        pushButton_update->setGeometry(QRect(520, 120, 81, 30));
        checkBox_vit_vent = new QCheckBox(groupBox_4);
        checkBox_vit_vent->setObjectName("checkBox_vit_vent");
        checkBox_vit_vent->setGeometry(QRect(10, 100, 201, 20));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(170, 180, 451, 311));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 30, 101, 16));
        QFont font2;
        font2.setBold(true);
        label_3->setFont(font2);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 120, 101, 16));
        label_4->setFont(font2);
        lblMPAccX = new QLabel(groupBox_2);
        lblMPAccX->setObjectName("lblMPAccX");
        lblMPAccX->setGeometry(QRect(30, 50, 91, 20));
        lblMPAccY = new QLabel(groupBox_2);
        lblMPAccY->setObjectName("lblMPAccY");
        lblMPAccY->setGeometry(QRect(30, 70, 91, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 50, 16, 20));
        label_5->setFont(font2);
        label_5->setWordWrap(true);
        lblMPAccZ = new QLabel(groupBox_2);
        lblMPAccZ->setObjectName("lblMPAccZ");
        lblMPAccZ->setGeometry(QRect(30, 90, 91, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 70, 16, 20));
        label_6->setFont(font2);
        label_6->setWordWrap(true);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 90, 16, 20));
        label_8->setFont(font2);
        label_8->setWordWrap(true);
        lblMPGyrX = new QLabel(groupBox_2);
        lblMPGyrX->setObjectName("lblMPGyrX");
        lblMPGyrX->setGeometry(QRect(30, 140, 91, 20));
        lblMPGyrY = new QLabel(groupBox_2);
        lblMPGyrY->setObjectName("lblMPGyrY");
        lblMPGyrY->setGeometry(QRect(30, 160, 91, 20));
        lblMPGyrZ = new QLabel(groupBox_2);
        lblMPGyrZ->setObjectName("lblMPGyrZ");
        lblMPGyrZ->setGeometry(QRect(30, 180, 91, 20));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 180, 16, 20));
        label_9->setFont(font2);
        label_9->setWordWrap(true);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 160, 16, 20));
        label_7->setFont(font2);
        label_7->setWordWrap(true);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 140, 16, 20));
        label_10->setFont(font2);
        label_10->setWordWrap(true);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 210, 81, 16));
        label_11->setFont(font2);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 270, 31, 20));
        label_12->setFont(font2);
        label_12->setWordWrap(true);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 230, 31, 20));
        label_13->setFont(font2);
        label_13->setWordWrap(true);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 250, 41, 20));
        label_14->setFont(font2);
        label_14->setWordWrap(true);
        lblMPphi = new QLabel(groupBox_2);
        lblMPphi->setObjectName("lblMPphi");
        lblMPphi->setGeometry(QRect(50, 230, 71, 20));
        lblMPpsi = new QLabel(groupBox_2);
        lblMPpsi->setObjectName("lblMPpsi");
        lblMPpsi->setGeometry(QRect(50, 270, 71, 20));
        lblMPtheta = new QLabel(groupBox_2);
        lblMPtheta->setObjectName("lblMPtheta");
        lblMPtheta->setGeometry(QRect(50, 250, 71, 20));
        openGLWidget = new ObjectOpenGL(groupBox_2);
        openGLWidget->setObjectName("openGLWidget");
        openGLWidget->setGeometry(QRect(130, 40, 300, 251));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 180, 151, 141));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush30(QColor(0, 0, 0, 128));
        brush30.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush30);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush31(QColor(0, 0, 0, 128));
        brush31.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush31);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush32(QColor(0, 0, 0, 128));
        brush32.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush32);
#endif
        groupBox_5->setPalette(palette5);
        lcdNumber_dist = new QLCDNumber(groupBox_5);
        lcdNumber_dist->setObjectName("lcdNumber_dist");
        lcdNumber_dist->setGeometry(QRect(10, 40, 91, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush13);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush15);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush33(QColor(0, 0, 0, 128));
        brush33.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush33);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush13);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush34(QColor(0, 0, 0, 128));
        brush34.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush34);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush13);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush35(QColor(0, 0, 0, 128));
        brush35.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush35);
#endif
        lcdNumber_dist->setPalette(palette6);
        lcdNumber_dist->setFrameShadow(QFrame::Plain);
        lcdNumber_dist->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_lumi = new QLCDNumber(groupBox_5);
        lcdNumber_lumi->setObjectName("lcdNumber_lumi");
        lcdNumber_lumi->setEnabled(false);
        lcdNumber_lumi->setGeometry(QRect(10, 100, 91, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush13);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush15);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush36(QColor(252, 175, 62, 128));
        brush36.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush36);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush13);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush37(QColor(252, 175, 62, 128));
        brush37.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush37);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush13);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush38(QColor(252, 175, 62, 128));
        brush38.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush38);
#endif
        lcdNumber_lumi->setPalette(palette7);
        lcdNumber_lumi->setFont(font1);
        lcdNumber_lumi->setLayoutDirection(Qt::LeftToRight);
        lcdNumber_lumi->setFrameShadow(QFrame::Plain);
        lcdNumber_lumi->setSegmentStyle(QLCDNumber::Flat);
        lblVLValue_press_4 = new QLabel(groupBox_5);
        lblVLValue_press_4->setObjectName("lblVLValue_press_4");
        lblVLValue_press_4->setGeometry(QRect(110, 50, 31, 21));
        lblVLValue_press_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_press_4->setWordWrap(true);
        lblVLValue_anemo_4 = new QLabel(groupBox_5);
        lblVLValue_anemo_4->setObjectName("lblVLValue_anemo_4");
        lblVLValue_anemo_4->setGeometry(QRect(110, 110, 31, 21));
        lblVLValue_anemo_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblVLValue_anemo_4->setWordWrap(true);
        radioButton_dist = new QRadioButton(groupBox_5);
        radioButton_dist->setObjectName("radioButton_dist");
        radioButton_dist->setGeometry(QRect(10, 20, 95, 20));
        radioButton_dist->setFont(font2);
        radioButton_dist->setChecked(true);
        radioButton_lumi = new QRadioButton(groupBox_5);
        radioButton_lumi->setObjectName("radioButton_lumi");
        radioButton_lumi->setGeometry(QRect(10, 80, 95, 20));
        radioButton_lumi->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 632, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PROJET CAN 2021", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Capteur pression MPL115A1", nullptr));
        lblVLValue_press->setText(QCoreApplication::translate("MainWindow", "Pression ", nullptr));
        lblVLValue_anemo->setText(QCoreApplication::translate("MainWindow", "Vitesse du vent", nullptr));
        lblVLValue_press_2->setText(QCoreApplication::translate("MainWindow", "hPa", nullptr));
        lblVLValue_anemo_2->setText(QCoreApplication::translate("MainWindow", "km/h", nullptr));
        lblVLValue_press_5->setText(QCoreApplication::translate("MainWindow", "%rH", nullptr));
        lblVLValue_press_6->setText(QCoreApplication::translate("MainWindow", "Humidit\303\251", nullptr));
        checkBox_led->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        lblVLValue_press_3->setText(QCoreApplication::translate("MainWindow", "Moteur", nullptr));
        lblVLValue_press_7->setText(QCoreApplication::translate("MainWindow", "\302\260C", nullptr));
        lblVLValue_press_8->setText(QCoreApplication::translate("MainWindow", "Temp\303\251rature", nullptr));
        pushButton_update->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        checkBox_vit_vent->setText(QCoreApplication::translate("MainWindow", "Coupl\303\251 \303\240 la la vitesse du vent", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "MPU9250", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Acc\303\251l\303\251ration", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Gyroscope", nullptr));
        lblMPAccX->setText(QCoreApplication::translate("MainWindow", "Undefined", nullptr));
        lblMPAccY->setText(QCoreApplication::translate("MainWindow", "Undefined", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lblMPAccZ->setText(QCoreApplication::translate("MainWindow", "Undefined", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        lblMPGyrX->setText(QCoreApplication::translate("MainWindow", "Undefined", nullptr));
        lblMPGyrY->setText(QCoreApplication::translate("MainWindow", "Undefined", nullptr));
        lblMPGyrZ->setText(QCoreApplication::translate("MainWindow", "Undefined", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Angles", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "psi", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "phi", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "theta", nullptr));
        lblMPphi->setText(QCoreApplication::translate("MainWindow", "Undefined", nullptr));
        lblMPpsi->setText(QCoreApplication::translate("MainWindow", "Undefined", nullptr));
        lblMPtheta->setText(QCoreApplication::translate("MainWindow", "Undefined", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "VL6180X", nullptr));
        lblVLValue_press_4->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        lblVLValue_anemo_4->setText(QCoreApplication::translate("MainWindow", "Lux", nullptr));
        radioButton_dist->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
        radioButton_lumi->setText(QCoreApplication::translate("MainWindow", "Luminosit\303\251", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
