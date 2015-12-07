#include <WPILib.h>

#include "EntechRobot.h"

EntechRobot::EntechRobot()
    : m_drive(NULL)
    , m_shooter(NULL)
    , m_lw(NULL)
{
    m_robotSubsystems.clear();
}

EntechRobot::~EntechRobot() {}

void EntechRobot::RobotInit()
{
    m_lw = LiveWindow::GetInstance();
    m_drive = new DriveSubsystem("drive");
    m_shooter = new ShooterSubsystem("shooter");

    // Manage sub-systems
    for (std::list<RobotSubsystem*>::iterator it = m_robotSubsystems.begin();
         it != m_robotSubsystems.end(); ++it) {
        (*it)->RobotInit();
    }
}

void EntechRobot::DisabledInit()
{

    // Manage sub-systems
    for (std::list<RobotSubsystem*>::iterator it = m_robotSubsystems.begin();
         it != m_robotSubsystems.end(); ++it) {
        (*it)->DisabledInit();
    }
}

void EntechRobot::DisabledPeriodic()
{

    // Manage sub-systems
    for (std::list<RobotSubsystem*>::iterator it = m_robotSubsystems.begin();
         it != m_robotSubsystems.end(); ++it) {
        (*it)->DisabledPeriodic();
    }
}

void EntechRobot::TeleopInit()
{

    // Manage sub-systems
    for (std::list<RobotSubsystem*>::iterator it = m_robotSubsystems.begin();
         it != m_robotSubsystems.end(); ++it) {
        (*it)->TeleopInit();
    }
}

void EntechRobot::TeleopPeriodic()
{
    // Manage sub-systems
    for (std::list<RobotSubsystem*>::iterator it = m_robotSubsystems.begin();
         it != m_robotSubsystems.end(); ++it) {
        (*it)->TeleopPeriodic();
    }
}

void EntechRobot::AutonomousInit()
{

    // Manage sub-systems
    for (std::list<RobotSubsystem*>::iterator it = m_robotSubsystems.begin();
         it != m_robotSubsystems.end(); ++it) {
        (*it)->AutonomousInit();
    }
}

void EntechRobot::AutonomousPeriodic()
{

    // Manage sub-systems
    for (std::list<RobotSubsystem*>::iterator it = m_robotSubsystems.begin();
         it != m_robotSubsystems.end(); ++it) {
        (*it)->AutonomousPeriodic();
    }
}

void EntechRobot::TestInit()
{

    // Manage sub-systems
    for (std::list<RobotSubsystem*>::iterator it = m_robotSubsystems.begin();
         it != m_robotSubsystems.end(); ++it) {
        (*it)->TestInit();
    }
}

void EntechRobot::TestPeriodic()
{
    m_lw->Run();

    // Manage sub-systems
    for (std::list<RobotSubsystem*>::iterator it = m_robotSubsystems.begin();
         it != m_robotSubsystems.end(); ++it) {
        (*it)->TestPeriodic();
    }
}

void EntechRobot::RegisterSubsystem(RobotSubsystem* subsys)
{
    m_robotSubsystems.push_back(subsys);
}

START_ROBOT_CLASS(EntechRobot);
