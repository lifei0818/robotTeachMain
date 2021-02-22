#include "editWidget.h"

#include <QHBoxLayout>

#include <QDebug>

editWidget::editWidget()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("background: rgba(203, 203, 203, 40);");
    this->setFixedSize(1280, 800);

    initUI();
    initState();
    connectSignalSlot();
}

editWidget::~editWidget()
{

}

void editWidget::setCurrentIndex(int index)
{
    m_stackWidget->setCurrentIndex(index);

    if(index == 0){
        QString strIp, strPort;
        robotData::Instance()->getIP(strIp, strPort);

        m_editIP->setText(strIp);
        m_editPort->setText(strPort);
    }else if(index == 1){
        radioProgramChanged();
    }else if(index == 2){
        readLog();
    }
}

void editWidget::initUI()
{
    m_stackWidget = new QStackedWidget();

    QWidget* widgetConnect = new QWidget();

    QLabel* labelIP = new QLabel(tr("地址 : "));
    labelIP->setStyleSheet("border: 0px solid black;");

    QRegExp regIp("^((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)$");
    QRegExpValidator* validatorIp = new QRegExpValidator(regIp, this);

    m_editIP = new QLineEdit();
    m_editIP->setValidator(validatorIp);
    m_editIP->setStyleSheet("background: white;border: 1px solid black;");

    QHBoxLayout* layoutIP = new QHBoxLayout();

    layoutIP->addWidget(labelIP);
    layoutIP->addWidget(m_editIP);

    QLabel* labelPort = new QLabel(tr("端口 : "));
    labelPort->setStyleSheet("border: 0px solid black;");

    QRegExp regPort("6[0-5]{2}[0-3][0-5]|[1-5]\\d{4}|[1-9]\\d{1,3}|[1-9]\\d{2}|[1-9]\\d|\\d");
    QRegExpValidator* validatorPort = new QRegExpValidator(regPort, this);

    m_editPort = new QLineEdit();
    m_editPort->setValidator(validatorPort);
    m_editPort->setStyleSheet("background: white;border: 1px solid black;");

    QHBoxLayout* layoutPort = new QHBoxLayout();

    layoutPort->addWidget(labelPort);
    layoutPort->addWidget(m_editPort);

    QVBoxLayout* layoutConnect = new QVBoxLayout(widgetConnect);

    layoutConnect->addLayout(layoutIP);
    layoutConnect->addLayout(layoutPort);

    m_stackWidget->addWidget(widgetConnect);

    QWidget* widgetProgram = new QWidget();

    m_radioHR = new QRadioButton("HR");
    m_radioHR->setStyleSheet("border: 0px solid gray;");

    m_radioABB = new QRadioButton("ABB");
    m_radioABB->setStyleSheet("border: 0px solid gray;");

    m_radioKUKA = new QRadioButton("KUKA");
    m_radioKUKA->setStyleSheet("border: 0px solid gray;");

    m_radioFANUC = new QRadioButton("FANUC");
    m_radioFANUC->setStyleSheet("border: 0px solid gray;");

    m_radioYASKAWA = new QRadioButton("YASKAWA");
    m_radioYASKAWA->setStyleSheet("border: 0px solid gray;");

    QVBoxLayout* layoutRadioButton = new QVBoxLayout();

    layoutRadioButton->addWidget(m_radioHR);
    layoutRadioButton->addWidget(m_radioABB);
    layoutRadioButton->addWidget(m_radioKUKA);
    layoutRadioButton->addWidget(m_radioFANUC);
    layoutRadioButton->addWidget(m_radioYASKAWA);

    m_widgetType = new QWidget();
    m_widgetType->setStyleSheet("border: 0px solid gray;");

    m_radioDownfile = new QRadioButton(tr("模板文件"));
    m_radioDownfile->setStyleSheet("border: 0px solid gray;");

    m_radioUpfile = new QRadioButton(tr("学生文件"));
    m_radioUpfile->setStyleSheet("border: 0px solid gray;");

    QHBoxLayout* layoutType = new QHBoxLayout(m_widgetType);
    layoutType->setContentsMargins(0, 0, 0, 0);

    layoutType->addWidget(m_radioDownfile);
    layoutType->addWidget(m_radioUpfile);

    m_listWidgetProgram = new QListWidget();

    QVBoxLayout* layoutProgram = new QVBoxLayout();

    layoutProgram->addWidget(m_widgetType);
    layoutProgram->addWidget(m_listWidgetProgram);

    QHBoxLayout* layoutWidgetProgram = new QHBoxLayout(widgetProgram);

    layoutWidgetProgram->addLayout(layoutRadioButton);
    layoutWidgetProgram->addLayout(layoutProgram);

    m_stackWidget->addWidget(widgetProgram);

    QWidget* widgetLog = new QWidget();

    m_textLog = new QTextEdit();
    m_textLog->setFocusPolicy(Qt::NoFocus);
    m_textLog->setStyleSheet("background: white;border: 1px solid black;");

    QVBoxLayout* layoutLog = new QVBoxLayout(widgetLog);

    layoutLog->addWidget(m_textLog);

    m_stackWidget->addWidget(widgetLog);

    m_buttonOK = new QPushButton(tr("确定"));
    m_buttonOK->setFixedSize(80, 50);

    m_buttonCancel = new QPushButton(tr("取消"));
    m_buttonCancel->setFixedSize(80, 50);

    QHBoxLayout* layoutButton = new QHBoxLayout();

    layoutButton->addWidget(m_buttonOK);
    layoutButton->addWidget(m_buttonCancel);

    QWidget* widgetMain = new QWidget();
    widgetMain->setStyleSheet("background: rgba(203, 203, 203);border: 1px solid black;");
    widgetMain->setFixedSize(450, 300);

    QVBoxLayout* layoutMain = new QVBoxLayout(widgetMain);

    layoutMain->addWidget(m_stackWidget);
    layoutMain->addLayout(layoutButton);

    QVBoxLayout* layoutWidget = new QVBoxLayout(this);
    layoutWidget->setAlignment(Qt::AlignCenter);

    layoutWidget->addWidget(widgetMain);

    m_stackWidget->setCurrentIndex(3);
}

void editWidget::initState()
{
    m_radioHR->setChecked(true);

    m_radioDownfile->setChecked(true);
}

void editWidget::connectSignalSlot()
{
    QObject::connect(m_radioHR, SIGNAL(toggled(bool)), this, SLOT(radioProgramChanged()));
    QObject::connect(m_radioABB, SIGNAL(toggled(bool)), this, SLOT(radioProgramChanged()));
    QObject::connect(m_radioKUKA, SIGNAL(toggled(bool)), this, SLOT(radioProgramChanged()));
    QObject::connect(m_radioFANUC, SIGNAL(toggled(bool)), this, SLOT(radioProgramChanged()));
    QObject::connect(m_radioYASKAWA, SIGNAL(toggled(bool)), this, SLOT(radioProgramChanged()));

    QObject::connect(m_radioUpfile, SIGNAL(toggled(bool)), this, SLOT(radioTypeChanged()));
    QObject::connect(m_radioDownfile, SIGNAL(toggled(bool)), this, SLOT(radioTypeChanged()));

    QObject::connect(m_buttonOK, &QPushButton::clicked, this, &editWidget::buttonOKClicked);
    QObject::connect(m_buttonCancel, &QPushButton::clicked, this, &editWidget::buttonCancelClicked);

    QObject::connect(m_buttonOK, &QPushButton::pressed, this, &editWidget::buttonPressed);
    QObject::connect(m_buttonOK, &QPushButton::released, this, &editWidget::buttonReleased);

    QObject::connect(m_buttonCancel, &QPushButton::pressed, this, &editWidget::buttonPressed);
    QObject::connect(m_buttonCancel, &QPushButton::released, this, &editWidget::buttonReleased);
}

void editWidget::readLog()
{
    QDir PATH = QDir(qApp->applicationDirPath());
    PATH.cd("config");
    QString logPath = PATH.path() + QString("/Log.txt");

    m_textLog->clear();

    QFile file(logPath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        m_textLog->setText(in.readAll());

        file.close();
    }
}

void editWidget::radioTypeChanged()
{
    m_listWidgetProgram->clear();

    m_listProgram = robotData::Instance()->getFileList();

    int count = m_listProgram.size() / 5;

    for(int i = 0; i < count; ++i){
        if(m_radioDownfile->isChecked()){
            if(m_listProgram[5*i + 4] == QString("2")){
                m_listWidgetProgram->addItem(m_listProgram[5*i]);
            }
        }else if(m_radioUpfile->isChecked()){
            if(m_listProgram[5*i + 4] == QString("1")){
                m_listWidgetProgram->addItem(m_listProgram[5*i]);
            }
        }
    }
}

void editWidget::radioProgramChanged()
{
    QString tmpPath = robotData::Instance()->getPath();

    if(robotData::Instance()->getDownloadState()){
        m_widgetType->show();

        m_radioDownfile->setChecked(true);

        radioTypeChanged();
    }else{
        m_widgetType->hide();

        QStringList files;

        if(m_radioHR->isChecked()){
            QDir dir(tmpPath + QString("/robotTeachHR/config/robotProgram"));
            QStringList nameFilters;
            nameFilters << QString("*.program");
            files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
        }else if(m_radioABB->isChecked()){

        }else if(m_radioKUKA->isChecked()){

        }else if(m_radioFANUC->isChecked()){

        }else if(m_radioYASKAWA->isChecked()){

        }

        m_listWidgetProgram->clear();
        for(int i = 0; i < files.size(); ++i){
            m_listWidgetProgram->addItem(files[i]);
        }
    }
}

void editWidget::buttonOKClicked()
{
    int index = m_stackWidget->currentIndex();

    if((index == 1) && (robotData::Instance()->getConnectState() == false)){
        m_stackWidget->setCurrentIndex(0);
        return;
    }

    switch(index){
    case 0:{
        QString ipaddr = m_editIP->text();

        QString port = m_editPort->text();

        if((ipaddr == QString("")) || (port == QString(""))){
            robotData::Instance()->showInfo(QString("地址和端口为空!"));
            return;
        }

        if(robotData::Instance()->setIP(ipaddr, port) == false){
            robotData::Instance()->showInfo(QString("设置失败"));
            return;
        }

        QDir PATH = QDir(qApp->applicationDirPath());
        PATH.cd("config");
        QString pathCache = PATH.path() + QString("/Cache.ini");

        QSettings st(pathCache, QSettings::IniFormat);
        st.setValue("user/teacherIP", ipaddr);
        st.setValue("user/teacherPort", port);

//            QString tmp = QString("vncviewer -PasswordFile /home/osrc/.vnc/passwd -ViewOnly 0 -DotWhenNoCursor ") + m_editIP->text();

//            char*  ch;
//            QByteArray ba = tmp.toLatin1(); // must
//            ch = ba.data();

//            FILE *fp;
//            do{
//                fp = popen(ch, "w");
//                if(!fp){
//                    printf("fail to start vncviewer\n");
//                }
//            }
//            while(!fp);
//            pclose(fp);

    }
        break;
    case 1:{
        QListWidgetItem* item = m_listWidgetProgram->currentItem();

        if(item == nullptr){
            return;
        }

        int type = 0;

        QString tmpPath = robotData::Instance()->getPath();
        QString name = item->text();
        QString path;
        if(m_radioHR->isChecked()){
            type = 0;
            path = tmpPath + QString("/robotTeachHR/config/robotProgram") + QString("/") + name;
        }else if(m_radioABB->isChecked()){
            type = 1;
        }else if(m_radioKUKA->isChecked()){
            type = 2;
        }else if(m_radioFANUC->isChecked()){
            type = 3;
        }else if(m_radioYASKAWA->isChecked()){
            type = 4;
        }

        if(robotData::Instance()->getDownloadState()){
            robotData::Instance()->downFile(name);
        }else{
            robotData::Instance()->upFile(name, path, type);
        }
    }
        break;
    default:
        break;
    }

    this->hide();
}

void editWidget::buttonCancelClicked()
{
    this->hide();
}

void editWidget::buttonPressed()
{
    QPushButton* m_button = (QPushButton*)sender();

    m_button->setStyleSheet("background: gray;");
}

void editWidget::buttonReleased()
{
    QPushButton* m_button = (QPushButton*)sender();

    m_button->setStyleSheet("background: rgba(203, 203, 203, 40);");
}
