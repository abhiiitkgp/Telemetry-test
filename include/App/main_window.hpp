/**
 * @file /include/App/main_window.hpp
 *
 * @brief Qt based gui for App.
 *
 * @date November 2010
 **/
#ifndef App_MAIN_WINDOW_H
#define App_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace App {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

    //void ReadSettings(); // Load up qt program settings at startup
    //void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
    //void on_button_connect_clicked(bool check );
    void on_pushButton_clicked(bool checked);
    void on_pushButton_4_clicked(bool checked);
    //void on_pushButton_3_clicked(bool checked);
   // void on_checkbox_use_environment_stateChanged(int state);


    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView();
    // no idea why this can't connect automatically

    void updateLoggingView1();
    void updateLoggingView2();
    void updateLoggingView3();
    void updateLoggingView4();
    void updateLoggingView5();
    void updateLoggingView6();
private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace App

#endif // App_MAIN_WINDOW_H
