#ifndef FRMINPUT_H
#define FRMINPUT_H

#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include <QMouseEvent>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QPushButton>
#include <QTimer>

namespace Ui
{
    class frmInput;
}

/**
* @brief 虚拟键盘
*/

class frmInput : public QWidget
{
    Q_OBJECT

public:
    explicit frmInput(QWidget *parent = 0);
    ~frmInput();

    static frmInput *Instance() {  ///< 单例模式,保证一个程序只存在一个输入法实例对象
        if (!_instance) {
            _instance = new frmInput;
        }
        return _instance;
    }

    void Init();  ///< 初始化面板状态

    void setMain(QWidget* main);  ///< 设置键盘所属窗口

private:
    void InitForm();                ///< 初始化窗体数据
    void InitProperty();            ///< 初始化属性
    void ChangeFont();              ///< 改变字体大小
    void ShowPanel();               ///< 显示输入法面板

    void changeType(QString type);  ///< 改变输入法类型
    void changeLetter(bool isUpper);///< 改变字母大小写

    void insertValue(QString value);///< 插入值到当前焦点控件
    void deleteValue();             ///< 删除当前焦点控件的一个字符

protected:
    void mouseMoveEvent(QMouseEvent *e);  ///< 鼠标拖动事件
    void mousePressEvent(QMouseEvent *e);  ///< 鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *);  ///< 鼠标松开事件

private:

    QWidget* Main;  ///< 键盘所属窗口

    Ui::frmInput *ui;
    static frmInput *_instance;     ///< 实例对象

    int frmWidth;                   ///< 窗体宽度
    int frmHeight;                  ///< 窗体高度

    QPoint mousePoint;              ///< 鼠标拖动自定义标题栏时的坐标
    bool mousePressed;              ///< 鼠标是否按下

    bool isPress;                   ///< 是否长按退格键
    QPushButton *btnPress;          ///< 长按按钮
    QTimer *timerPress;             ///< 退格键定时器

    bool isFirst;                   ///< 是否首次加载

    QWidget *currentWidget;         ///< 当前焦点的对象
    QLineEdit *currentLineEdit;     ///< 当前焦点的单行文本框
    QTextEdit *currentTextEdit;     ///< 当前焦点的多行文本框
    QPlainTextEdit *currentPlain;   ///< 当前焦点的富文本框
    QTextBrowser *currentBrowser;   ///< 当前焦点的文本浏览框

    QString currentEditType;        ///< 当前焦点控件的类型
    int btnFontSize;                ///< 当前输入法面板按钮字体大小
    int labFontSize;                ///< 当前输入法面板标签字体大小

    QString currentType;            ///< 当前输入法类型

private slots:
    /**
     * @brief 焦点切换时键盘显示与文本内容编辑
     * @param oldWidget 旧窗口
     * @param nowWidget 新窗口
     */
    void focusChanged(QWidget *oldWidget, QWidget *nowWidget);  ///< 焦点改变事件槽函数处理
    void btn_clicked();  ///< 输入法面板按键处理
    void changeStyle(QString topColor, QString bottomColor,
                     QString borderColor, QString textColor);  ///< 改变输入法面板样式
    void reClicked();  ///< 定时器处理退格键

signals:
    void signalKeyBoardHide();
};

#endif // FRMINPUT_H
