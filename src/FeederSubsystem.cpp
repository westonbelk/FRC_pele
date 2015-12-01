#include <WPILib.h>

#include "FeederSubsystem.h"
#include "RobotSubsystem.h"
#include "RobotConstants.h"

FeederSubsystem::FeederSubsystem(std::string name)
    : RobotSubsystem(name)
    , m_joystick(NULL)
	, m_feedermotor(NULL)
    , m_loadermotor(NULL)
    , m_shootermotor1(NULL)
    , m_shootermotor2(NULL)
{
}

FeederSubsystem::~FeederSubsystem()
{   
}

/********************************** Init Routines *************************************/

void FeederSubsystem::RobotInit() 
{
    m_joystick = new Joystick(0);

    m_feedermotor = new Victor(c_feedermotor_PWMid);
    m_loadermotor = new Victor(c_loadermotor_PWMid);
    m_shootermotor1 = new Victor(c_shootermotor1_PWMid);
    m_shootermotor2 = new Victor(c_shootermotor2_PWMid);
}

void FeederSubsystem::DisabledInit() 
{
}

void FeederSubsystem::TeleopInit() 
{
}

void FeederSubsystem::AutonomousInit() 
{
}

void FeederSubsystem::TestInit() 
{
}

/********************************** Periodic Routines *************************************/

void FeederSubsystem::DisabledPeriodic()  
{
    /* Disable all of the motors */
    m_feedermotor->Set(0, 0);
    m_loadermotor->Set(0, 0);
    m_shootermotor1->Set(0, 0);
    m_shootermotor2->Set(0, 0);
}

void FeederSubsystem::TeleopPeriodic() 
{
    if (m_joystick->GetRawButton(c_jsthumb_id)) {
        m_feedermotor->Set(1, 0);
        m_loadermotor->Set(1, 0);
        m_shootermotor1->Set(-1, 0);
        m_shootermotor2->Set(-1, 0);
    }
    else {
    	m_feedermotor->Set(0, 0);
        m_loadermotor->Set(0, 0);
        m_shootermotor1->Set(0, 0);
        m_shootermotor2->Set(0, 0);
    }
}

void FeederSubsystem::AutonomousPeriodic() 
{
}

void FeederSubsystem::TestPeriodic() 
{
}
