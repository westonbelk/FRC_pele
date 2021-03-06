#ifndef _ENTECH_ROBOT_H
#define _ENTECH_ROBOT_H

#include <WPILib.h>
#include <list>

#include "RobotSubsystem.h"
#include "DriveSubsystem.h"
#include "ShooterSubsystem.h"
#include "CameraSubsystem.h"

#define ENTECH_ROBOT dynamic_cast<EntechRobot&>(RobotBase::getInstance())

class EntechRobot : public IterativeRobot {
public:
    EntechRobot();
    virtual ~EntechRobot();

    void RegisterSubsystem(RobotSubsystem*);

private:
    DriveSubsystem* m_drive;
    ShooterSubsystem* m_shooter;
    CameraSubsystem* m_camera;
    LiveWindow* m_lw;


    std::list<RobotSubsystem*> m_robotSubsystems;

    virtual void RobotInit();
    virtual void DisabledInit();
    virtual void DisabledPeriodic();
    virtual void TeleopInit();
    virtual void TeleopPeriodic();
    virtual void AutonomousInit();
    virtual void AutonomousPeriodic();
    virtual void TestInit();
    virtual void TestPeriodic();
};

#endif
