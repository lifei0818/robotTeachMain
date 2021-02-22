#ifndef EDITWIDGET_H
#define EDITWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTextEdit>
#include <QStackedWidget>
#include <QTextStream>
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QSettings>

#include "macroDefine.hpp"

#include "robotData/robotData.h"

/**
* @brief 编辑与显示窗口
* 编辑教师端地址与端口;显示文件列表并选择
*/

class editWidget : public QWidget
{
    Q_OBJECT
public:
    editWidget();
    ~editWidget();

    /**
     * @brief 切换窗口显示内容
     * @param index 0:地址编辑 1:文件列表 2:更新日志
     */
    void setCurrentIndex(int index);

private:
    void initUI();
    void initState();
    void connectSignalSlot();

    void readLog();  ///< 读取日志

private:
    QLineEdit* m_editIP;  ///< 编辑地址

    QLineEdit* m_editPort;  ///< 编辑端口

    QRadioButton* m_radioHR;  ///< HR示教器
    QRadioButton* m_radioABB;  ///< ABB示教器
    QRadioButton* m_radioKUKA;  ///< KUKA示教器
    QRadioButton* m_radioFANUC;  ///< FANUC示教器
    QRadioButton* m_radioYASKAWA;  ///< YASKAWA示教器

    QWidget* m_widgetType;  ///< 示教器类型窗口

    QRadioButton* m_radioUpfile;  ///< 模板文件
    QRadioButton* m_radioDownfile;  ///< 学生文件

    QListWidget* m_listWidgetProgram;  ///< 文件列表

    QTextEdit* m_textLog;  ///< 日志窗口

    QStackedWidget* m_stackWidget;  ///< 当前输入法类型

    QPushButton* m_buttonOK;  ///< 当前输入法类型
    QPushButton* m_buttonCancel;  ///< 当前输入法类型

    QList<QString> m_listProgram;  ///< 当前输入法类型

private slots:
    void radioTypeChanged();  ///< 示教器类型切换处理
    void radioProgramChanged();  ///< 文件类型切换处理

    void buttonOKClicked();  ///< 确定按钮
    void buttonCancelClicked();  ///< 取消按钮

    void buttonPressed();  ///< 按钮按下
    void buttonReleased();  ///< 按钮松开
};

#endif // EDITWIDGET_H
