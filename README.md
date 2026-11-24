## Self driving Car project
The goal is for the car to avoid objects and maneuver itself without issue.
Attached are three infrared sensors and an ultrasonic sensor. <br>
Every infrared had to be calibrated first to get correct readings. The calculation was done via excel and I just pasted the results into the corresponding code-block. <br>
Having four sensors is a bit overkill but since it is a project I did in my free time means I get to choose the rules.

## Parts
**Arduino Uno** <br>
**Motorshield L298N** <br>
**1xSharp Sensor GP2Y0A02YK0F** <br>
**2xSharp Sensor GP2Y0A21YK0F** <br>

## Infrared calculation
This section contains the calibration data and linearization math for Sharp infrared distance 
sensors used for this project. 
It includes general measurements along with the derived coefficients needed to convert raw ADC readings into distance values in software. <br>

The infrared sensors output an analog voltage that is not linear with distance. The raw ADC value drops as the measured distance increases.
´´´
ADC ≈ m / (length + k) + d
´´´
**length** [cm] **k**, **m**, **d** are sensor-specific constants determined from calibration measurements.
k is the small offset that keeps the denominator well-behaved and improves the fit.
To use this in the firmware, the equation is rearranged to solve for distance:
´´´
l = m / (ADC - d) - k
´´´
Equivalently, using the inverted coefficients:
´´´
m' = 1/m and d' = d/m
l = 1 / (m' * ADC + d') - k
´´´
# Calibration Data
Measurements were taken at fixed distances (10-130 cm) by recording the averaged ADC value at each distance.

For each sensor, the coefficients m and d are computed by fitting a straight line to the transformed data: <br>
the x-axis is the inverse of (l + k), and the y-axis is the raw ADC value. The slope of that line is m, the intercept is d.

For each calibration table:
<ol>
  <li>Compute the inverse ADC value 1 / ADC.</li>
  <li>Compute 1 / (l + k) for each measured distance.</li>
  <li>Fit a line through the points (1 / (l + k), ADC). The slope is m, the intercept is d.</li>
  <li>Store the inverted forms m' = 1/m and d' = d/m for fast distance calculation in firmware.</li>
</ol> 
The k value is tuned per sensor to minimize the residual error of the fit. 
A value near zero (as on the right sensor) means the response is nearly ideal inverse; 
negative or larger positive values compensate for deviations at close or far range.

To see how the calculations were implemented view the corresponding code sections.
