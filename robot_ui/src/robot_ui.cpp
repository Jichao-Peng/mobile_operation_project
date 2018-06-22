//
// Created by leo on 18-6-1.
//

#include "robot_ui.h"

namespace robot_ui
{
    RobotBaseUI::RobotBaseUI(QWidget *parent) : rviz::Panel(parent)
    {
        //底盘运动操作面板
        QHBoxLayout *HLayout1 = new QHBoxLayout;
        QHBoxLayout *HLayout2 = new QHBoxLayout;
        QHBoxLayout *HLayout3 = new QHBoxLayout;
        QHBoxLayout *HLayout4 = new QHBoxLayout;
        blanck_button_1 = new QPushButton(this);
        HLayout1->addWidget(blanck_button_1);
        move_forward_button = new QPushButton("Forward",this);
        HLayout1->addWidget(move_forward_button);
        blanck_button_2 = new QPushButton(this);
        HLayout1->addWidget(blanck_button_2);

        move_left_button = new QPushButton("Left",this);
        HLayout2->addWidget(move_left_button);
        blanck_button_3 = new QPushButton(this);
        HLayout2->addWidget(blanck_button_3);
        move_right_button = new QPushButton("Right",this);
        HLayout2->addWidget(move_right_button);

        blanck_button_4 = new QPushButton(this);
        HLayout3->addWidget(blanck_button_4);
        move_back_button = new QPushButton("Back",this);
        HLayout3->addWidget(move_back_button);
        blanck_button_5 = new QPushButton(this);
        HLayout3->addWidget(blanck_button_5);

        turn_left_button = new QPushButton("Turn Left",this);
        HLayout4->addWidget(turn_left_button);
        turn_right_button = new QPushButton("Turn Right",this);
        HLayout4->addWidget(turn_right_button);

        QVBoxLayout *VLayout = new QVBoxLayout;
        VLayout->addLayout(HLayout1);
        VLayout->addLayout(HLayout2);
        VLayout->addLayout(HLayout3);
        VLayout->addLayout(HLayout4);
        setLayout(VLayout);


        move_forward_button->setAutoRepeat(true);
        move_left_button->setAutoRepeat(true);
        move_right_button->setAutoRepeat(true);
        move_back_button->setAutoRepeat(true);
        turn_left_button->setAutoRepeat(true);
        turn_right_button->setAutoRepeat(true);

        connect(move_forward_button, SIGNAL(pressed()), this, SLOT(on_MoveForwardButton_clicked()));
        connect(move_left_button, SIGNAL(pressed()), this, SLOT(on_MoveLeftButton_clicked()));
        connect(move_right_button, SIGNAL(pressed()), this, SLOT(on_MoveRightButton_clicked()));
        connect(move_back_button, SIGNAL(pressed()), this, SLOT(on_MoveBackButton_clicked()));
        connect(turn_left_button, SIGNAL(pressed()), this, SLOT(on_TurnLeftButton_clicked()));
        connect(turn_right_button, SIGNAL(pressed()), this, SLOT(on_TurnRightButton_clicked()));

        //定时器
        timer = new QTimer;
        connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
        timer->start(100);

        //发布
        robot_base_ui_pub = node.advertise<geometry_msgs::Twist>("/NMotionCtrlTopic/GeoTwistSetInstantVelocity",1000);
    }

    void RobotBaseUI::Update()
    {
        robot_base_ui_pub.publish(command);

        //每次循环都执行清零操作，如果停止按键则发送零速度
        command.angular.x = 0;
        command.angular.y = 0;
        command.angular.z = 0;
        command.linear.x = 0;
        command.linear.y = 0;
        command.linear.z = 0;
    }


    void RobotBaseUI::on_MoveForwardButton_clicked()
    {
        command.linear.x = 0.05;
    }

    void RobotBaseUI::on_MoveLeftButton_clicked()
    {
        command.linear.y = 0.05;
    }

    void RobotBaseUI::on_MoveRightButton_clicked()
    {
        command.linear.y = -0.05;
    }

    void RobotBaseUI::on_MoveBackButton_clicked()
    {
        command.linear.x = -0.05;
    }

    void RobotBaseUI::on_TurnLeftButton_clicked()
    {
        command.angular.z = 0.05;
    }

    void RobotBaseUI::on_TurnRightButton_clicked()
    {
        command.angular.z = -0.05;
    }

    //save和load是rviz固定的接口
    void RobotBaseUI::save(rviz::Config config) const
    {
        rviz::Panel::save(config);
    }

    void RobotBaseUI::load(const rviz::Config &config)
    {
        rviz::Panel::load(config);
    }
}

//申明此类是rviz的一个插件
#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(robot_ui::RobotBaseUI, rviz::Panel);
