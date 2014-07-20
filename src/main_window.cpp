/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/App/main_window.hpp"
//#include <qwt/qwt_thermo.h>
#include "qwt/qwt_thermo.h"
#include <qwt/qwt_dial_needle.h>
#include <qwt/qwt_compass_rose.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace App {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , qnode(argc,argv)
{
    ui.setupUi(this);
    // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application
    qnode.init();
    //ReadSettings();
    setWindowIcon(QIcon(":/images/icon.png"));

    ui.Compass->setNeedle(new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Ray,false, Qt::red));

    // QwtSimpleCompassRose r;

    // r.setNumThorns(2);

    //    ui.Compass->setRose(r);

    //  ui.Compass->setRose(&r);

    //    QwtDialNeedle h = new QwtDialNeedle();

    //    ui.Compass->setNeedle(h);

    ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

    /*********************
    ** Logging
    **********************/
    //ui.view_logging->setModel(qnode.loggingModel());


    /*********************
    ** Auto Start
    **********************/
    /*if ( ui.checkbox_remember_settings->isChecked() ) {
        on_pushButton_clicked(true);
    }*/
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
    QMessageBox msgBox;
    msgBox.setText("Couldn't find the ros master.");
    msgBox.exec();
    close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

/*void MainWindow::on_button_connect_clicked(bool check ) {
    if ( ui.checkbox_use_environment->isChecked() ) {
        if ( !qnode.init() ) {
            showNoMasterMessage();
        } else {
            ui.button_connect->setEnabled(false);
        }
    } else {
        if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
                   ui.line_edit_host->text().toStdString()) ) {
            showNoMasterMessage();
        } else {
            ui.button_connect->setEnabled(false);
            ui.line_edit_master->setReadOnly(true);
            ui.line_edit_host->setReadOnly(true);
            ui.line_edit_topic->setReadOnly(true);
        }
    }
}*/

bool haha=true;

void MainWindow::on_pushButton_clicked(bool Checked)
{
    //    QString mystring;
    //    mystring.append((qnode._msg+"\n").c_str());
    //    ui.textBrowser->append(mystring);
    haha=true;

    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));
    QObject::connect(&qnode, SIGNAL(loggingUpdated1()), this, SLOT(updateLoggingView1()));
    QObject::connect(&qnode, SIGNAL(loggingUpdated2()), this, SLOT(updateLoggingView2()));
    QObject::connect(&qnode, SIGNAL(loggingUpdated3()), this, SLOT(updateLoggingView3()));
    QObject::connect(&qnode, SIGNAL(loggingUpdated4()), this, SLOT(updateLoggingView4()));
    QObject::connect(&qnode, SIGNAL(loggingUpdated5()), this, SLOT(updateLoggingView5()));
    QObject::connect(&qnode, SIGNAL(loggingUpdated6()), this, SLOT(updateLoggingView6()));



}

/*void MainWindow::on_pushButton_2_clicked(bool Checked)
{
    QObject::connect(&qnode, SIGNAL(loggingUpdated1()), this, SLOT(updateLoggingView1()));
    QObject::connect(&qnode, SIGNAL(loggingUpdated2()), this, SLOT(updateLoggingView2()));
    QObject::connect(&qnode, SIGNAL(loggingUpdated3()), this, SLOT(updateLoggingView3()));


}
void MainWindow::on_pushButton_3_clicked(bool Checked)
{
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView4()));
    QObject::connect(&qnode, SIGNAL(loggingUpdated1()), this, SLOT(updateLoggingView5()));
    QObject::connect(&qnode, SIGNAL(loggingUpdated1()), this, SLOT(updateLoggingView6()));


}*/

void MainWindow::on_pushButton_4_clicked(bool Checked)
{

    haha=false;

}


/*void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
    bool enabled;
    if ( state == 0 ) {
        enabled = true;
    } else {
        enabled = false;
    }
    ui.line_edit_master->setEnabled(enabled);
    ui.line_edit_host->setEnabled(enabled);
    //ui.line_edit_topic->setEnabled(enabled);

}*/

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
    //QString s(qnode._msg.c_str());
    // ui.textBrowser->append(s);
    if(haha==true)
    {
    int j= atoi(qnode._msg.c_str());
    ui.Thermo->setValue(j);
    //ui.doubleSpinBox->setValue(j);

}
}
void MainWindow::updateLoggingView1()
{
    if(haha==true)
    {
    int j= atoi(qnode._msg1.c_str());
    ui.doubleSpinBox_8->setValue(j);

}
}
void MainWindow::updateLoggingView2()
{
    if(haha==true)
    {
    int j= atoi(qnode._msg2.c_str());
    ui.doubleSpinBox_7->setValue(j);
}
}
void MainWindow::updateLoggingView3()
{
    if(haha==true)
    {

    int j= atoi(qnode._msg3.c_str());
    ui.doubleSpinBox_6->setValue(j);
    ui.Compass->setValue(j);
    //ui.Compass->setNeedle(new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Ray,false, Qt::red);
    ui.Compass->setValue(j);
}
}
void MainWindow::updateLoggingView4()
{
    if(haha==true)
    {

    int j= atoi(qnode._msg4.c_str());
    ui.doubleSpinBox_5->setValue(j);
    }
}
void MainWindow::updateLoggingView5()
{
    if(haha==true)
    {
    int j= atoi(qnode._msg5.c_str());
    ui.doubleSpinBox_4->setValue(j);

}
}
void MainWindow::updateLoggingView6()
{
    if(haha==true)
    {
    int j= atoi(qnode._msg6.c_str());
    ui.doubleSpinBox_3->setValue(j);

}
}




/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::closeEvent(QCloseEvent *event)
{

    //    WriteSettings();
    QMainWindow::closeEvent(event);
}


}  // namespace App

