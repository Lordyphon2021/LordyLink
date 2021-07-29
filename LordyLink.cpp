#include "LordyLink.h"


#include <qstring.h>
#include<qlistwidget.h>
#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QIODevice>




using namespace std;





LordyLink::LordyLink(QWidget *parent)
    : QMainWindow(parent)
{
    
    
    ui.setupUi(this);
    //QObject::connect(ui.Q_UpdateLordyphonButton, SIGNAL(clicked()), SLOT(download_wrapper()));
	QObject::connect(ui.Q_UpdateLordyphonButton, SIGNAL(clicked()), SLOT(usb_write()));
	
	 filehandler = new Filehandler(ui.Q_UpdateFeedback);
    
}








void LordyLink::download(Filehandler* filehandler)
{
    QString location = "ftp://stefandeisenberger86881@ftp.lordyphon.com/lordyphon_proto.txt";
    QString path = "C:/Users/trope/OneDrive/Desktop/Neuer Ordner/lordyphon_proto.txt"; //Replace this with your file
    filehandler->download(location, path);
    
}


void LordyLink::download_wrapper()
{
    download(filehandler);
}


void LordyLink::usb_write()
{
    
    Usb.find_lordyphon_port();
    
    if (Usb.identify_lordyphon()) {

        ui.QUsbStatus->addItem("Success!");

    }
    
    

}





