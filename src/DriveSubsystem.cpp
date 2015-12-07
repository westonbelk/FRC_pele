#include <WPILib.h>

#include "DriveSubsystem.h"
#include "RobotSubsystem.h"
#include "RobotConstants.h"
#include <iostream>

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

DriveSubsystem::~DriveSubsystem() {}

/********************************** Init Routines *************************************/

void DriveSubsystem::RobotInit()
{
    m_joystick = new Joystick(0);

    m_flmotor = new Victor(c_flmotor_PWMid);
    m_frmotor = new Victor(c_frmotor_PWMid);
    m_rlmotor = new Victor(c_rlmotor_PWMid);
    m_rrmotor = new Victor(c_rrmotor_PWMid);

    m_robotDrive = new RobotDrive(m_flmotor, m_rlmotor, m_frmotor, m_rrmotor);
    m_robotDrive->SetSafetyEnabled(false);

    m_robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, c_kflmotor_inversed);
    m_robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, c_krlmotor_inversed);
    m_robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, c_kfrmotor_inversed);
    m_robotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, c_krrmotor_inversed);
}

void DriveSubsystem::DisabledInit() {}

void DriveSubsystem::TeleopInit() {}

void DriveSubsystem::AutonomousInit() {}

void DriveSubsystem::TestInit() {}

/********************************** Periodic Routines *************************************/

void DriveSubsystem::DisabledPeriodic()
{
    m_robotDrive->MecanumDrive_Cartesian(0.0, 0.0, 0.0, 0.0);
}

/*
    * The gyroscope is not implemented at all.
    * In the future I plan for it to be optional.
*/
void DriveSubsystem::TeleopPeriodic()
{
    double jsX, jsY, jsT;

    if (m_joystick) {
        jsX = m_joystick->GetX();
        jsY = m_joystick->GetY();
    }
    else {
        jsX = 0.0;
        jsY = 0.0;
    }

    /* Rotate the robot only if the trigger being held. */
    if (m_joystick->GetTrigger()) {
        jsT = m_joystick->GetTwist();
    }
    else {
        jsT = 0.0;
    }

    /* Move the robot */
    m_robotDrive->MecanumDrive_Cartesian(jsX, jsY, jsT);
}

void DriveSubsystem::AutonomousPeriodic() {}

void DriveSubsystem::TestPeriodic() {}
