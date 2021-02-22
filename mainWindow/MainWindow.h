#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QTextEdit>
#include <QRadioButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QProcess>
#include <QTimer>
#include <QtNetwork>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QApplication>
#include <QSettings>
#include <QFileInfoList>
#include <QEvent>
#include <QKeyEvent>
#include <QScrollBar>
#include <QProgressBar>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#ifdef Q_OS_WIN32
    #include <stdlib.h>
    #include <JlCompress.h>
    #include "windows.h"
#endif

#include "MyThread.h"
#include "macroDefine.hpp"

#include "settingWidget.h"
#include "editWidget.h"

#include "robotData/robotData.h"

/**
 * @brief 程序主界面
 */
class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    void initUI();
    void connectSignalSlot();

    void initButton();  ///< 初始化示教器按钮

    void robotStart();  ///< 启动自定义线程示教器

    void timeSleep();  ///< 休眠一段时间

//    void CopyOrMove(QString, QString, bool);

protected:
    void keyPressEvent(QKeyEvent*);  ///< 重载键盘点击事件,拦截回车键点击

private: 
    QString m_localIP;  ///< 本机IP
    QString m_pathCache;  ///< 缓存文件路径

    QString m_IP;  ///< 服务端IP
    int m_Port;  ///< 服务端端口

    QPushButton* m_robotTeachEFT;  ///< EFT示教器按钮
    QPushButton* m_robotTeachHR;  ///< HR示教器按钮
    QPushButton* m_robotTeachABB;  ///< ABB示教器按钮
    QPushButton* m_robotTeachKUKA;  ///< KUKA示教器按钮
    QPushButton* m_robotTeachFNK;  ///< FNK示教器按钮
    QPushButton* m_robotTeachAC;  ///< AC示教器按钮

    QPushButton* m_buttonMore;  ///< 功能窗口按钮

    QLineEdit* m_editIPAddr;  ///< 编辑地址
    QLineEdit* m_editIPPort;  ///< 编辑端口

    QLabel* m_labelLocalAddr;  ///< 显示本机IP

    QTimer* m_timer;  ///< 用于定时检测地址

#ifdef Q_OS_WIN32
    QProcess* myProcess = nullptr;
#endif

    QPushButton* m_buttonChangeScreen;  ///< 触摸屏切换按钮

    QTimer* m_timerChanged;  ///< 触摸屏切换按钮定时器

    settingWidget* m_widgetSetting;  ///< 功能列表窗口
    editWidget* m_widgetEdit;  ///< 编辑与显示窗口

    QDialog* m_tipWidget;  ///< 提示窗口
    QLabel* m_labelTip;  ///< 程序启动与更新时提示信息

private slots:
    void buttonChangeScreenPressed();  ///< 触摸屏切换按钮按下
    void buttonChangeScreenReleased();  ///< 触摸屏切换按钮松开

    void changeScreen();  ///< 切换触摸屏点击时方向

    void tcpConfigChanged();  ///< 处理服务端地址端口改变

    void buttonEFTConnectClicked();  ///< 启动EFT示教器
    void buttonHRConnectClicked();  ///< 启动HR示教器
    void buttonABBConnectClicked();  ///< 启动ABB示教器
    void buttonKUKAConnectClicked();  ///< 启动KUKA示教器
    void buttonFNKConnectClicked();  ///< 启动FNK示教器
    void buttonACConnectClicked();  ///< 启动AC示教器

    void tcpLocalChanged();  ///< 处理本机地址改变

#ifdef Q_OS_WIN32
    void buttonGetNumberClicked();
    void buttonSetNumberClicked();
#endif

    void buttonMoreClicked();  ///< 弹出功能列表窗口

    /**
     * @brief 弹出显示与编辑窗口
     * @param index 0:地址编辑 1:文件列表 2:更新日志
     */
    void showEditWidget(int);

    void showInfo(QString);  ///< 显示提示信息

    void showTip(bool);  ///< 程序启动提示框显示与掩藏
    void showUpdateTip();  ///< 更新提示框显示

signals:
    void signalTipShow(bool);  ///< 程序启动提示框显示信号

    void signalUpdateRobotSoft();  ///< 更新提示框显示信号
private:
    QThread* firstThread;  ///< QT线程
    MyThread* myObjectThread;  ///< 自定义线程
};

#endif // MAINWINDOW_H
