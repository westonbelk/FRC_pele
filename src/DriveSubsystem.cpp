#include "WPILib.h"
#include "RobotSubsystem.h"
#include "RobotConstants.h"

DriveSubsystem::DriveSubsystem(std::string name)
    : RobotSubsystem(name)
    , m_joystick(NULL)
    , m_frmotor(NULL)
    , m_flmotor(NULL)
    , m_rrmotor(NULL)
    , m_rlmotor(NULL)
    , m_robotDrive(NULL)
{
}

DriveSubsystem::~DriveSubsystem()
{	
}

/********************************** Init Routines *************************************/

void DriveSubsystem::RobotInit() 
{
    m_joystick = new Joystick(0);
    m_flmotor = new CanTalonSRX(c_flmotor_CANid);
    m_frmotor = new CanTalonSRX(c_frmotor_CANid);
    m_rlmotor = new CanTalonSRX(c_rlmotor_CANid);
    m_rrmotor = new CanTalonSRX(c_rrmotor_CANid);
    m_robotDrive = new RobotDrive(m_flmotor, m_rlmotor, m_frmotor, m_rrmotor);
    m_robotDrive->SetSafetyEnabled(false);
    m_robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
    m_robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
    m_robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
    m_robotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
}

void DriveSubsystem::DisabledInit() 
{
}

void DriveSubsystem::TeleopInit() 
{
}

void DriveSubsystem::AutonomousInit() 
{
}

void DriveSubsystem::TestInit() 
{
}

/********************************** Periodic Routines *************************************/

void DriveSubsystem::DisabledPeriodic()  
{
    m_robotDrive->MecanumDrive_Cartesian(0.0, 0.0, 0.0, 0.0);
}

void DriveSubsystem::TeleopPeriodic() 
{
    double jsX, jsY, jsT;
    double gyro_angle;

    if (m_joystick) {
        jsX = -m_joystick->GetX();
        jsY = -m_joystick->GetY();
        jsT =  m_joystick->GetTwist();
        gyro_angle = 0.0;
    } else {
        jsX = 0.0;
        jsY = 0.0;
        jsT = 0.0;
        gyro_angle = 0.0;
    }
    
    m_robotDrive->MecanumDrive_Cartesian(jsX, jsY, jsT, gyro_angle);
}

void DriveSubsystem::AutonomousPeriodic() 
{
}

void DriveSubsystem::TestPeriodic() 
{
}
