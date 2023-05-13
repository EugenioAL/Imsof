/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_pic;
    QLabel *DimLabel;
    QLabel *dims;
    QLabel *percentDarkLabel;
    QLabel *pDark;
    QLabel *infolabel;
    QLabel *numBlobsLabel;
    QLabel *nBlobs;
    QLabel *maxBlobAreaLabel;
    QLabel *mBArea;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 645);
        MainWindow->setMaximumSize(QSize(900, 645));
        QPalette palette;
        QBrush brush(QColor(163, 163, 163, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(212, 212, 212, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(161, 161, 161, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(53, 220, 220, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(90, 213, 240, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        MainWindow->setPalette(palette);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("applications-graphics")));
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 211, 31));
        label->setMaximumSize(QSize(300, 200));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 20, 121, 31));
        pushButton->setMaximumSize(QSize(250, 100));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(30, 70, 500, 500));
        label_pic->setMaximumSize(QSize(500, 500));
        DimLabel = new QLabel(centralwidget);
        DimLabel->setObjectName("DimLabel");
        DimLabel->setGeometry(QRect(570, 150, 111, 51));
        DimLabel->setMaximumSize(QSize(150, 75));
        QFont font2;
        font2.setPointSize(14);
        DimLabel->setFont(font2);
        dims = new QLabel(centralwidget);
        dims->setObjectName("dims");
        dims->setGeometry(QRect(690, 150, 141, 51));
        dims->setMaximumSize(QSize(150, 75));
        dims->setFont(font2);
        percentDarkLabel = new QLabel(centralwidget);
        percentDarkLabel->setObjectName("percentDarkLabel");
        percentDarkLabel->setGeometry(QRect(570, 200, 121, 51));
        percentDarkLabel->setMaximumSize(QSize(150, 75));
        percentDarkLabel->setFont(font2);
        pDark = new QLabel(centralwidget);
        pDark->setObjectName("pDark");
        pDark->setGeometry(QRect(700, 200, 121, 51));
        pDark->setMaximumSize(QSize(150, 75));
        pDark->setFont(font2);
        infolabel = new QLabel(centralwidget);
        infolabel->setObjectName("infolabel");
        infolabel->setGeometry(QRect(590, 100, 191, 51));
        infolabel->setMaximumSize(QSize(200, 60));
        infolabel->setFont(font);
        numBlobsLabel = new QLabel(centralwidget);
        numBlobsLabel->setObjectName("numBlobsLabel");
        numBlobsLabel->setGeometry(QRect(570, 250, 150, 51));
        numBlobsLabel->setMaximumSize(QSize(150, 75));
        numBlobsLabel->setFont(font2);
        nBlobs = new QLabel(centralwidget);
        nBlobs->setObjectName("nBlobs");
        nBlobs->setGeometry(QRect(730, 250, 121, 51));
        nBlobs->setMaximumSize(QSize(150, 75));
        nBlobs->setFont(font2);
        maxBlobAreaLabel = new QLabel(centralwidget);
        maxBlobAreaLabel->setObjectName("maxBlobAreaLabel");
        maxBlobAreaLabel->setGeometry(QRect(570, 300, 131, 51));
        maxBlobAreaLabel->setMaximumSize(QSize(150, 75));
        maxBlobAreaLabel->setFont(font2);
        mBArea = new QLabel(centralwidget);
        mBArea->setObjectName("mBArea");
        mBArea->setGeometry(QRect(710, 300, 121, 51));
        mBArea->setMaximumSize(QSize(150, 75));
        mBArea->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Imsof", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Load Your Image", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
        label_pic->setText(QString());
        DimLabel->setText(QCoreApplication::translate("MainWindow", "Dimensions:", nullptr));
        dims->setText(QCoreApplication::translate("MainWindow", "W: 0 H: 0", nullptr));
        percentDarkLabel->setText(QCoreApplication::translate("MainWindow", "Occupancy %:", nullptr));
        pDark->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        infolabel->setText(QCoreApplication::translate("MainWindow", "Image Information", nullptr));
        numBlobsLabel->setText(QCoreApplication::translate("MainWindow", "Number of Blobs:", nullptr));
        nBlobs->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        maxBlobAreaLabel->setText(QCoreApplication::translate("MainWindow", "Max Blob Area:", nullptr));
        mBArea->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
