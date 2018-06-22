//
// Created by leo on 18-6-1.
//

#ifndef PROJECT_ROBOT_UI_H
#define PROJECT_ROBOT_UI_H

#include <ros/ros.h>
#include <rviz/panel.h>
#include <ros/console.h>
#include <geometry_msgs/Twist.h>

#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

namespace robot_ui
{
    class RobotBaseUI : public rviz::Panel
    {
        Q_OBJECT
    public:
        RobotBaseUI(QWidget *parent = 0);

        //重载rviz::Panel中的函数，用于保存、加载配置文件中的数据，在这个plugin中，数据就是topic的名称
        virtual void load(const rviz::Config &config);
        virtual void save(rviz::Config config) const;


    protected:
        ros::NodeHandle node;
        ros::Publisher robot_base_ui_pub;

        QPushButton *move_forward_button;
        QPushButton *move_back_button;
        QPushButton *move_left_button;
        QPushButton *move_right_button;
        QPushButton *turn_left_button;
        QPushButton *turn_right_button;

        QPushButton *blanck_button_1;
        QPushButton *blanck_button_2;
        QPushButton *blanck_button_3;
        QPushButton *blanck_button_4;
        QPushButton *blanck_button_5;

        QTimer *timer;
        geometry_msgs::Twist command;

    private Q_SLOTS:
        void on_MoveForwardButton_clicked();
        void on_MoveLeftButton_clicked();
        void on_MoveRightButton_clicked();
        void on_MoveBackButton_clicked();
        void on_TurnLeftButton_clicked();
        void on_TurnRightButton_clicked();

        void Update();

    };
}

#endif //PROJECT_ROBOT_UI_H
