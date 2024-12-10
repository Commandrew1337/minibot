// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with tank steering and an Xbox controller.
 */
class Robot : public frc::TimedRobot {
 private:
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX	victor1_left_motor{3};	
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX	victor2_left_motor{4};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX	victor3_right_motor{5};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX	victor4_right_motor{6};
  frc::XboxController m_driverController{0};

 public:
  Robot() {

    // We need to invert one side of the drivetrain so that positive voltages
    // result in both sides moving forward. Depending on how your robot's
    // gearbox is constructed, you might have to invert the left side instead.
    victor3_right_motor.SetInverted(true);
    victor4_right_motor.SetInverted(true);
  }

  void TeleopPeriodic() override {
    // Drive with tank style
    double left_stick = m_driverController.GetLeftY();
    double right_stick = -m_driverController.GetRightY();
    victor1_left_motor.Set(left_stick);
    victor2_left_motor.Set(left_stick);
    victor3_right_motor.Set(right_stick);
    victor4_right_motor.Set(right_stick);

  }
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
