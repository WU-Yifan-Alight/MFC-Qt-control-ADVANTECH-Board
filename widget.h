#ifndef WIDGET_H
#define WIDGET_H
#include <Windows.h>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include "AdvMotApi.h"
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QTimer *t;
    void updateData();
    DEVLIST	list_avadevice[20];

    DWORD	m_dwDevNum;
    HAND    devicehandle;
    HAND    axishandle;
    HAND 	m_Devhand[20];
    HAND	m_Axishand[20];
    BOOL 	Deviceopenflag[20];
    BOOL	Servoflag[20];
    BOOL	Nmotionflag[20];
    BOOL	Pmotionflag[20];




private slots:
    void on_pushButton_OpenDevice_clicked();

    void on_pushButton_CloseDevice_clicked();

    void on_pushButton_OpenCloseServo_clicked();

    void on_comboBox_Chose_AvailableDevice_currentIndexChanged(const QString &arg1);

    void on_pushButton_PositiveMove_clicked();

    void on_pushButton_NegativeMove_clicked();

    void on_pushButton_Stop_clicked();

protected:
    void closeEvent(QCloseEvent *event) ;
    void SetParameters( );

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
