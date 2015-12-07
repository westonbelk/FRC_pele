#include <WPILib.h>

#include "RobotSubsystem.h"
#include "EntechRobot.h"

RobotSubsystem::RobotSubsystem(std::string name)
    : m_name(name)
    , m_counter(0)
{
    ENTECH_ROBOT.RegisterSubsystem(this);
}

RobotSubsystem::~RobotSubsystem() {}

const char* RobotSubsystem::GetName()
{
    return m_name.c_str();
}

/********************************** Init Routines *************************************/

void RobotSubsystem::RobotInit()
{
    printf("Running RobotSubsystem::RobotInit() for '%s'\n", GetName());
}

void RobotSubsystem::DisabledInit()
{
    printf("Running RobotSubsystem::DisabledInit() for '%s'\n", GetName());
}

void RobotSubsystem::TeleopInit()
{
    printf("Running RobotSubsystem::TeleopInit() for '%s'\n", GetName());
}

void RobotSubsystem::AutonomousInit()
{
    printf("Running RobotSubsystem::AutonomousInit() for '%s'\n", GetName());
}

void RobotSubsystem::TestInit()
{
    printf("Running RobotSubsystem::TestInit() for '%s'\n", GetName());
}

/********************************** Periodic Routines *************************************/

void RobotSubsystem::DisabledPeriodic()
{
    if (!(m_counter % 100)) {
        m_counter = 0;
        printf("Running RobotSubsystem::DisabledPeriodic() for '%s'\n", GetName());
    }
    m_counter++;
}

void RobotSubsystem::TeleopPeriodic()
{
    if (!(m_counter % 100)) {
        m_counter = 0;
        printf("Running RobotSubsystem::TeleopPeriodic() for '%s'\n", GetName());
    }
    m_counter++;
}

void RobotSubsystem::AutonomousPeriodic()
{
    if (!(m_counter % 100)) {
        m_counter = 0;
        printf("Running RobotSubsystem::AutonomousPeriodic() for '%s'\n", GetName());
    }
    m_counter++;
}

void RobotSubsystem::TestPeriodic()
{
    if (!(m_counter % 100)) {
        m_counter = 0;
        printf("Running RobotSubsystem::TestPeriodic() for '%s'\n", GetName());
    }
    m_counter++;
}
