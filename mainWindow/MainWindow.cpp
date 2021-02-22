#include "MainWindow.h"

#include <QDebug>

using namespace std;

MainWindow::MainWindow()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(1280, 800);
    this->move(0, 0);
    this->setAutoFillBackground(true);
    this->setFocusPolicy(Qt::ClickFocus);

    initUI();

    connectSignalSlot();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initButton( )
{
    m_robotTeachEFT = new QPushButton(this);
    m_robotTeachEFT->setFocusPolicy(Qt::NoFocus);
    QIcon iconEFT(":/images/images/newRobot.png");
    m_robotTeachEFT->setIcon(iconEFT);
    m_robotTeachEFT->setIconSize(QSize(206,152));
    m_robotTeachEFT->setStyleSheet("QPushButton{"
                                  "border-radius:15px;"
                                  "}" );

    m_robotTeachHR = new QPushButton(this);
    m_robotTeachHR->setFocusPolicy(Qt::NoFocus);
    QIcon iconHR(":/images/images/HRrobot.png");
    m_robotTeachHR->setIcon(iconHR);
    m_robotTeachHR->setIconSize(QSize(206,152));
    m_robotTeachHR->setStyleSheet("QPushButton{"
                                  "border-radius:15px;"
                                  "}" );

    m_robotTeachABB = new QPushButton(this);
    m_robotTeachABB->setFocusPolicy(Qt::NoFocus);
    QIcon iconABB(":/images/images/ABBrobot.png");
    m_robotTeachABB->setIcon(iconABB);
    m_robotTeachABB->setIconSize(QSize(206,152));
    m_robotTeachABB->setStyleSheet("QPushButton{"
                                   "border-radius:15px;"
                                   "}" );

    m_robotTeachKUKA = new QPushButton(this);
    m_robotTeachKUKA->setFocusPolicy(Qt::NoFocus);
    QIcon iconKUKA(":/images/images/KUKArobot.png");
    m_robotTeachKUKA->setIcon(iconKUKA);
    m_robotTeachKUKA->setIconSize(QSize(206,152));
    m_robotTeachKUKA->setStyleSheet("QPushButton{"
                                    "border-radius:15px;"
                                    "}" );

    m_robotTeachFNK = new QPushButton(this);
    m_robotTeachFNK->setFocusPolicy(Qt::NoFocus);
    QIcon iconFNK(":/images/images/FNKrobot.png");
    m_robotTeachFNK->setIcon(iconFNK);
    m_robotTeachFNK->setIconSize(QSize(206,152));
    m_robotTeachFNK->setStyleSheet("QPushButton{"
                                   "border-radius:15px;"
                                   "}" );

    m_robotTeachAC = new QPushButton(this);
    m_robotTeachAC->setFocusPolicy(Qt::NoFocus);
    QIcon iconAC(":/images/images/ACrobot.png");
    m_robotTeachAC->setIcon(iconAC);
    m_robotTeachAC->setIconSize(QSize(206,152));
    m_robotTeachAC->setStyleSheet("QPushButton{"
                                  "border-radius:15px;"
                                  "}" );

#ifndef EFT_PLATFORM
    m_robotTeachEFT->hide();
    m_robotTeachHR->move(450,150);
    m_robotTeachABB->move(700,150);
    m_robotTeachKUKA->move(950,150);

    m_robotTeachFNK->move(578,352);
    m_robotTeachAC->move(828,352);
#else
    m_robotTeachEFT->move(450, 150);
    m_robotTeachHR->move(700,150);
    m_robotTeachABB->move(950,150);

    m_robotTeachKUKA->move(450,352);
    m_robotTeachFNK->move(700,352);
    m_robotTeachAC->move(950,352);
#endif

    QString path = robotData::Instance()->getPath();

    QString typeDir;
    int num = robotTeachEFT.indexOf(".");
    if(num != -1){
        typeDir = robotTeachEFT.mid(0,num);
    }else{
        typeDir = robotTeachEFT;
    }

    QFileInfo fileEFT(path + QString("/") + typeDir + QString("/") + robotTeachEFT);
    if(fileEFT.exists()){
        QObject::connect(m_robotTeachEFT, SIGNAL(clicked()), this, SLOT(buttonEFTConnectClicked()));
    }else{
        m_robotTeachEFT->setEnabled(false);
    }

    num = robotTeachHR.indexOf(".");
    if(num != -1){
        typeDir = robotTeachHR.mid(0,num);
    }else{
        typeDir = robotTeachHR;
    }

    QFileInfo fileHR(path + QString("/") + typeDir + QString("/") + robotTeachHR);
    if(fileHR.exists()){
        QObject::connect(m_robotTeachHR, SIGNAL(clicked()), this, SLOT(buttonHRConnectClicked()));
    }else{
        m_robotTeachHR->setEnabled(false);
    }

    num = robotTeachABB.indexOf(".");
    if(num != -1){
        typeDir = robotTeachABB.mid(0,num);
    }else{
        typeDir = robotTeachABB;
    }

    QFileInfo fileABB(path + QString("/") + typeDir + QString("/") + robotTeachABB);
    if(fileABB.exists()){
        QObject::connect(m_robotTeachABB, SIGNAL(clicked()), this, SLOT(buttonABBConnectClicked()));
    }else{
        m_robotTeachABB->setEnabled(false);
    }

    num = robotTeachKUKA.indexOf(".");
    if(num != -1){
        typeDir = robotTeachKUKA.mid(0,num);
    }else{
        typeDir = robotTeachKUKA;
    }

    QFileInfo fileKUKA(path + QString("/") + typeDir + QString("/") + robotTeachKUKA);
    if(fileKUKA.exists()){
        QObject::connect(m_robotTeachKUKA, SIGNAL(clicked()), this, SLOT(buttonKUKAConnectClicked()));
    }else{
        m_robotTeachKUKA->setEnabled(false);
    }

    num = robotTeachFNK.indexOf(".");
    if(num != -1){
        typeDir = robotTeachFNK.mid(0,num);
    }else{
        typeDir = robotTeachFNK;
    }

    QFileInfo fileFNK(path + QString("/") + typeDir + QString("/") + robotTeachFNK);
    if(fileFNK.exists()){
        QObject::connect(m_robotTeachFNK, SIGNAL(clicked()), this, SLOT(buttonFNKConnectClicked()));
    }else{
        m_robotTeachFNK->setEnabled(false);
    }

    num = robotTeachAC.indexOf(".");
    if(num != -1){
        typeDir = robotTeachAC.mid(0,num);
    }else{
        typeDir = robotTeachAC;
    }

    QFileInfo fileAC(path + QString("/") + typeDir + QString("/") + robotTeachAC);
    if(fileAC.exists()){
        QObject::connect(m_robotTeachAC, SIGNAL(clicked()), this, SLOT(buttonACConnectClicked()));
    }else{
        m_robotTeachAC->setEnabled(false);
    }
}

void MainWindow::initUI()
{
    QDir PATH = QDir(qApp->applicationDirPath());
    PATH.cdUp();
    robotData::Instance()->setPath(PATH.path());

    QLabel* labelIP = new QLabel(tr("控制器:"));

    QRegExp regIp("^((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)$");
    QRegExpValidator* validatorIp = new QRegExpValidator(regIp, this);

    m_editIPAddr = new QLineEdit();
    m_editIPAddr->setValidator(validatorIp);
    m_editIPAddr->setFocusPolicy(Qt::ClickFocus);
    m_editIPAddr->setFixedSize(150, 50);

    QRegExp regPort("6[0-5]{2}[0-3][0-5]|[1-5]\\d{4}|[1-9]\\d{1,3}|[1-9]\\d{2}|[1-9]\\d|\\d");
    QRegExpValidator* validatorPort = new QRegExpValidator(regPort, this);

    m_editIPPort = new QLineEdit();
    m_editIPPort->setValidator(validatorPort);
    m_editIPPort->setFocusPolicy(Qt::ClickFocus);
    m_editIPPort->setFixedSize(150, 50);

    QHBoxLayout* lineTCP = new QHBoxLayout();
    lineTCP->addWidget(labelIP);
    lineTCP->addWidget(m_editIPAddr);
    lineTCP->addWidget(m_editIPPort);

    QLabel* labelLocalAddrTitle = new QLabel(tr("本地IP地址:"));

    m_labelLocalAddr = new QLabel(m_localIP);

    QHBoxLayout* lineLocal=new QHBoxLayout();
    lineLocal->addWidget(labelLocalAddrTitle);
    lineLocal->addWidget(m_labelLocalAddr);

    QVBoxLayout* layoutAddress = new QVBoxLayout();
    layoutAddress->addLayout(lineTCP);
    layoutAddress->addLayout(lineLocal);

    QWidget* widgetTCP=new QWidget(this);
    widgetTCP->move(550,530);
    QVBoxLayout* layoutTCP = new QVBoxLayout(widgetTCP);
    layoutTCP->addLayout(layoutAddress);

    initButton();

    QPixmap pixLogo(":/images/images/logo.png");
    QLabel* labelLogo = new QLabel();
    labelLogo->setScaledContents(true);
    labelLogo->clear();
    labelLogo->setPixmap(pixLogo);
    labelLogo->show();

    QWidget* widgetLogo = new QWidget(this);
    widgetLogo->move(0,600);
    widgetLogo->setFixedSize(460,106);
    QHBoxLayout* layoutLogo = new QHBoxLayout(widgetLogo);
    layoutLogo->addWidget(labelLogo,Qt::AlignVCenter);

    QPixmap pixLogo1(":/images/images/robot.png");
    QLabel* labelLogo1 = new QLabel();
    labelLogo1->setScaledContents(true);
    labelLogo1->clear();
    labelLogo1->setPixmap(pixLogo1);
    labelLogo1->show();

    QWidget* widgetLogo1 = new QWidget(this);
    widgetLogo1->move(65,50);
    widgetLogo1->setFixedSize(294,523);
    QHBoxLayout* layoutLogo1 = new QHBoxLayout(widgetLogo1);
    layoutLogo1->addWidget(labelLogo1,Qt::AlignVCenter);

    QPixmap icon_more(":/images/images/more.png");
    m_buttonMore = new QPushButton(this);
    m_buttonMore->setStyleSheet("background-color: gray;");
    m_buttonMore->setFocusPolicy(Qt::ClickFocus);
    m_buttonMore->setFixedSize(100,75);
    m_buttonMore->setIcon(icon_more);
    m_buttonMore->setIconSize(QSize(100, 75));
    m_buttonMore->setFlat(true);
    m_buttonMore->move(50,700);

    QLabel* tipSystem = new QLabel(tr("HRP-M型工业机器人编程仿真软件教学平台"));
    tipSystem->setStyleSheet("font-size: 30px");

    QLabel* tipRobot = new QLabel(tr("未激活的机器人操作系统可加装软件包升级"));

    QWidget* widgetTip = new QWidget(this);
    widgetTip->setFixedSize(1280, 60);
    widgetTip->move(0,0);

    QHBoxLayout* layoutTip = new QHBoxLayout(widgetTip);
    layoutTip->setContentsMargins(40, 0, 20, 0);
    layoutTip->addWidget(tipSystem);
    layoutTip->addStretch();
    layoutTip->addWidget(tipRobot);

    QLabel* version = new QLabel(this);
    version->move(1150,720);
    version->resize(200,75);
    version->setText(tr("版本:") + QString("1.0.0.4"));

    m_timer = new QTimer(this);
    m_timer->start(1000);

#ifdef Q_OS_UNIX
    m_buttonChangeScreen = new QPushButton(this);
    m_buttonChangeScreen->setStyleSheet("checked{background-color: gray;}");
    m_buttonChangeScreen->resize(206,152);
    m_buttonChangeScreen->move(0,0);
    m_buttonChangeScreen->setFlat(true);

    m_timerChanged = new QTimer(this);
    m_timerChanged->setSingleShot(true);
#endif

    m_widgetSetting = new settingWidget();
    m_widgetSetting->setParent(this);
    m_widgetSetting->move(45, 100);
    m_widgetSetting->hide();

    m_widgetEdit = new editWidget();
    m_widgetEdit->setParent(this);
    m_widgetEdit->move(0, 0);
    m_widgetEdit->hide();

    m_tipWidget = new QDialog();
    m_tipWidget->setWindowFlags(Qt::FramelessWindowHint);
    m_tipWidget->setStyleSheet("background-color: rgb(255,255, 255)");
    m_tipWidget->resize(300,200);
    m_tipWidget->move(550,300);

    m_labelTip = new QLabel("test");
    m_labelTip->setAlignment(Qt::AlignCenter);
    m_labelTip->setStyleSheet("color: black;");
    m_labelTip->setFixedWidth(300);

    QProgressBar* tmp = new QProgressBar();
    tmp->setGeometry(100, 180, 120, 20);
    tmp->setOrientation(Qt::Horizontal);  // 水平方向
    tmp->setMinimum(0);  // 最小值
    tmp->setMaximum(0);  // 最大值

    QVBoxLayout* layoutTipWidget = new QVBoxLayout(m_tipWidget);
    layoutTipWidget->setAlignment(Qt::AlignCenter);

    layoutTipWidget->addWidget(m_labelTip);
    layoutTipWidget->addWidget(tmp);

    m_pathCache = PATH.path() + QString("/robotTeachMain/config/Cache.ini");

    QSettings st(m_pathCache, QSettings::IniFormat);
    m_IP = st.value("user/IP").toString();
    m_Port = st.value("user/Port").toInt();

    m_editIPAddr->setText(m_IP);
    m_editIPPort->setText(QString::number(m_Port, 10));
}

void MainWindow::connectSignalSlot()
{
#ifdef Q_OS_UNIX
    QObject::connect(m_buttonChangeScreen,SIGNAL(pressed()),this,SLOT(buttonChangeScreenPressed()));
    QObject::connect(m_buttonChangeScreen,SIGNAL(released()),this,SLOT(buttonChangeScreenReleased()));

    QObject::connect(m_timerChanged,SIGNAL(timeout()),this,SLOT(changeScreen()));
#endif

    QObject::connect(m_editIPAddr, SIGNAL(editingFinished()), this, SLOT(tcpConfigChanged()));
    QObject::connect(m_editIPPort, SIGNAL(editingFinished()), this, SLOT(tcpConfigChanged()));

    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(tcpLocalChanged()));
    QObject::connect(m_buttonMore, SIGNAL(clicked()), this, SLOT(buttonMoreClicked()));

    QObject::connect(robotData::Instance(), SIGNAL(signalShowInfo(QString)), this, SLOT(showInfo(QString)));

#ifdef Q_OS_WIN32
    QObject::connect(m_buttonGetNumber, SIGNAL(clicked()), this, SLOT(buttonGetNumberClicked()));
    QObject::connect(m_buttonSetNumber, SIGNAL(clicked()), this, SLOT(buttonSetNumberClicked()));
#endif

    QObject::connect(m_widgetSetting, SIGNAL(signalTipShowUpdate(bool)), this, SLOT(showUpdateTip()));
    QObject::connect(m_widgetSetting, SIGNAL(signalShowEditWidget(int)), this, SLOT(showEditWidget(int)));

    QObject::connect(this, SIGNAL(signalTipShow(bool)), this, SLOT(showTip(bool)));
}

void MainWindow::tcpConfigChanged()
{
    m_IP = m_editIPAddr->text();
    m_Port = m_editIPPort->text().toInt();

    QSettings st(m_pathCache, QSettings::IniFormat);
    st.setValue("user/IP", m_IP);
    st.setValue("user/Port", QString::number(m_Port));
}

void MainWindow::buttonEFTConnectClicked()
{
    robotData::Instance()->setRobotType(robotTeachEFT);

    robotStart();
}

void MainWindow::timeSleep()
{
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    QKeyEvent* eve = static_cast<QKeyEvent*>(event);

    if(event->type() == QEvent::KeyPress){
        if(eve->key() == Qt::Key_Return){
            return;
        }else{
            return QWidget::keyPressEvent(event);
        }
    }else{
        return QWidget::keyPressEvent(event);
    }
}

void MainWindow::buttonChangeScreenPressed()
{
    m_timerChanged->start(5000);
}

void MainWindow::buttonChangeScreenReleased()
{
    m_timerChanged->stop();
}

void MainWindow::changeScreen()
{
#ifdef Q_OS_WIN32
    return;
#endif
    FILE *fp;

    QFile fileInfo(QString("/usr/share/X11/xorg.conf.d/90-rotate-touch.conf"));
    if(fileInfo.exists())
    {
        if(QFile::remove(QString("/usr/share/X11/xorg.conf.d/90-rotate-touch.conf"))){
            do{
                fp = popen("sudo reboot", "w");
                if(!fp){
                    printf("fail to start shell\n");
                }
            }
            while(!fp);
        }
    }else{
        QDir PATH = QDir(qApp->applicationDirPath());
        PATH.cd("config");
        QString sourcePath = PATH.path() + QString("/90-rotate-touch.conf");

        if(QFile::copy(sourcePath,QString("/usr/share/X11/xorg.conf.d/90-rotate-touch.conf"))){
            do{
                fp = popen("sudo reboot", "w");
                if(!fp){
                    printf("fail to start shell\n");
                }
            }
            while(!fp);
        }
    }
    pclose(fp);
}

void MainWindow::tcpLocalChanged()
{
    m_localIP = QString("127.0.0.1");

    foreach (QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
    {
        QList<QNetworkAddressEntry> entryList = netInterface.addressEntries();
        foreach(QNetworkAddressEntry entry, entryList)
        {
            if(entry.ip().protocol() == QAbstractSocket::IPv4Protocol)
            {
                m_localIP = entry.ip().toString();
                if(m_localIP != QString("127.0.0.1")){
                    m_labelLocalAddr->setText(m_localIP);
                    robotData::Instance()->setLocalIP(m_localIP);
                    return;
                }
            }
        }
    }

    m_labelLocalAddr->setText(m_localIP);
}

void MainWindow::buttonHRConnectClicked()
{
    robotData::Instance()->setRobotType(robotTeachHR);

    robotStart();
}

void MainWindow::buttonABBConnectClicked()
{
    robotData::Instance()->setRobotType(robotTeachABB);

    robotStart();
}

void MainWindow::buttonKUKAConnectClicked()
{
    robotData::Instance()->setRobotType(robotTeachKUKA);

    robotStart();
}

void MainWindow::buttonFNKConnectClicked()
{
    robotData::Instance()->setRobotType(robotTeachFNK);

    robotStart();
}

void MainWindow::buttonACConnectClicked()
{
    robotData::Instance()->setRobotType(robotTeachAC);

    robotStart();
}

void MainWindow::robotStart()
{
    firstThread = new QThread;
    myObjectThread = new MyThread;
    myObjectThread->moveToThread(firstThread);
    signalTipShow(true);
    connect(firstThread,SIGNAL(started()),myObjectThread,SLOT(startThreadRobot()));
    connect(myObjectThread,SIGNAL(signalTipShow(bool)),this,SLOT(showTip(bool)));
    connect(firstThread,SIGNAL(finished()),myObjectThread,SLOT(deleteLater()));
    firstThread->start();
}

#ifdef Q_OS_WIN32

void MainWindow::CopyOrMove(QString path, QString target_path, bool iscopy)
{
    QFileInfo file_info(path);

    if(file_info.isDir()) //文件夹
    {
        QDir target_dir(target_path), dir(path);
        target_dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

        auto target_dirs = target_dir.entryList();
        if(!target_dirs.contains(file_info.fileName()))
            target_dir.mkpath(target_path + "/" + file_info.fileName());

        target_dir.cd(file_info.fileName());

        dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);

        auto files = dir.entryList();
        for(auto file : files)
        {
            QFile::copy(dir.path() + "/" + file, target_dir.path() + "/" + file);

            if(!iscopy)
                QFile::remove(dir.path() + "/" + file);
        }

        dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

        auto dirs = dir.entryList();
        for(auto dr : dirs)
        {
            CopyOrMove(path + "/" + dr, target_dir.path(), iscopy);
        }

        if(!iscopy)
        {
            dir.rmpath(path);
        }
    }
    else //文件
    {
        QFile::copy(path, target_path + "/" + file_info.fileName());

        if(!iscopy)
            QFile::remove(path);
    }
}

void MainWindow::buttonGetNumberClicked()
{
    time_sleep();
    QDir dll_path = QDir(qApp->applicationDirPath());
    QString tmp = QString(dll_path.path()) + QString("/HRlicence.dll");
    const wchar_t* tmp_path = reinterpret_cast<const wchar_t *>(tmp.utf16());//转换为宽字符

    HMODULE handle = nullptr;
    handle = ::LoadLibrary(tmp_path);

    if (handle == nullptr)
    {
        close();
        return ;
    }

    BOOL (WINAPI*GetDeviceString) (OUT LPCSTR *lpResult);
    BOOL (WINAPI* LpFree)(IN LPCSTR& lpResult);

    GetDeviceString = (BOOL(WINAPI*)(OUT LPCSTR *))GetProcAddress(handle, "GetDeviceString");
    LpFree = (BOOL(WINAPI* )(IN LPCSTR& ))GetProcAddress(handle, "LpFree");

    string number ;
    if(GetDeviceString!=nullptr&&LpFree!=nullptr){
        LPCSTR  lpDeviceID;
        BOOL bRt = GetDeviceString(&lpDeviceID);
        number = lpDeviceID;
        if(!lpDeviceID)
            LpFree(lpDeviceID);
    }

    FreeLibrary(handle);
    m_editLocalNumber->setText(QString::fromStdString(number));
}

void MainWindow::buttonSetNumberClicked()
{
    QString number = m_editProcessedNumber->text();

    QDir ini_path = PATH;
    ini_path.cdUp();
    QString tmp = QString(ini_path.path());
    tmp = tmp + QString("/robotServer/config/server.ini");

    QFile file(tmp);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::about(this, "提示", "file not open");
        cout << "failed to open cache file" << endl;
        exit(1);
    }

    QTextStream in(&file);
    in<<number<<"\n";
    file.close();

    QDir server_path = QDir(qApp->applicationDirPath());
    server_path.cdUp();
    server_path.cdUp();
    QString reStartPath = QString(server_path.path());
    reStartPath = reStartPath + QString("/robotServer/robotServerExe.exe");
    QProcess* reStartProcess = new QProcess();

    reStartProcess->startDetached(reStartPath);

    m_widgetCheckNumber->hide();
}

bool MainWindow::checkINI()
{
    QDir ini_path = PATH;
    ini_path.cdUp();
    QString tmp = QString(ini_path.path());

    tmp = tmp + QString("/robotServer/config/server.ini");

    QFileInfo fi(tmp);
    if(fi.isFile()){
        return true;
    }

    return false;
}

#endif

void MainWindow::buttonMoreClicked()
{
    if(m_widgetSetting->isHidden()){
        m_widgetSetting->show();
    }else{
        m_widgetSetting->hide();
    }
}

void MainWindow::showEditWidget(int index)
{
    m_widgetEdit->setCurrentIndex(index);

    m_widgetEdit->show();
}

void MainWindow::showInfo(QString str)
{
    QMessageBox::warning(this, QObject::tr("错误"), str);
}

void MainWindow::showTip(bool state)
{
    m_labelTip->setText("程序正在运行，请稍候");

    if(state){
        m_tipWidget->show();
    }else{
        m_tipWidget->hide();
    }
}

void MainWindow::showUpdateTip()
{
    m_labelTip->setText("更新完成后将会自动重启!");

    m_tipWidget->show();

    firstThread = new QThread;
    myObjectThread = new MyThread;
    myObjectThread->moveToThread(firstThread);

    connect(firstThread,SIGNAL(started()),myObjectThread,SLOT(startThreadUpdate()));
    connect(firstThread,SIGNAL(finished()),myObjectThread,SLOT(deleteLater()));
    firstThread->start();
}
