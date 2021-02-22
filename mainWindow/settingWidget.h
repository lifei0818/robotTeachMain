#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QMessageBox>
#include <QTimer>

#include "robotData/robotData.h"

/**
 * @brief 功能窗口
 */
class settingWidget : public QFrame
{
    Q_OBJECT
public:
    settingWidget();
    ~settingWidget();

private:
    void initUI();
    void connectSignalSlot();

private:
    QPushButton* m_buttonUpload;  ///< 上传文件按钮
    QPushButton* m_buttonDownload;  ///< 下载文件按钮
    QLabel* m_labelConnect;  ///< 显示与教师端连接状态,显示与教师端连接状态,红色为未连接
    QPushButton* m_buttonConnect;  ///< 教师端连接按钮
    QPushButton* m_buttonUpdate;  ///< 更新按钮
    QPushButton* m_buttonLog;  ///< 日志按钮
    QPushButton* m_buttonSettings;  ///< 设置按钮

    QTimer* m_timer;  ///< 定时器,用于定时查询连接状态

private slots:
    void updateState();  ///< 查询连接状态

    void buttonUplaodClilcked();  ///< 上传文件
    void buttonDownloadClicked();  ///< 下载文件

    void buttonConnectClicked();  ///< 教师端连接

    void buttonUpdateClicked();  ///< 更新
    void buttonLogClicked();  ///< 显示日志

    void buttonSettingClicked();  ///< 设置教师端地址端口

signals:
    void signalShowEditWidget(int);  ///< 设置编辑与显示窗口

    void signalTipShowUpdate(bool);  ///< 显示更新提示窗口
};

#endif // SETTINGWIDGET_H
