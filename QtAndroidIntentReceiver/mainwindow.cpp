#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtAndroidExtras>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lblTitle->setText("Qt Android Intent Receiver");
    /*
     * Get the Intent and display the received Extra Message
     */
    auto myActivity = QtAndroid::androidActivity();
    if(myActivity.isValid()){
        QAndroidJniObject intent = myActivity.callObjectMethod("getIntent", "()Landroid/content/Intent;");
            if (intent.isValid()) {
                QAndroidJniObject subject = QAndroidJniObject::fromString("EXTRA_MESSAGE");
                jboolean hasExtras = intent.callMethod<jboolean>("hasExtra", "(Ljava/lang/String;)Z", subject.object());
                if(hasExtras){
                    QAndroidJniObject extras = intent.callObjectMethod("getStringExtra", "(Ljava/lang/String;)Ljava/lang/String;", subject.object());
                    if(extras.isValid()){
                        ui->lblReceivedExtra->setText(extras.toString());
                    }else{
                        ui->lblReceivedExtra->setText("Extras is not valid");
                    }
                }else{
                    ui->lblReceivedExtra->setText("Intent does not have extras");
                }
            }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
