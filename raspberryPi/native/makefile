TARGET = helloRaspberry switch_led interrupt led_pwm tone_buzzer hard_tone_buzzer i2c_rgb_led i2c_rgb_led_switch i2c_servo fnd_cnt rgb_switch_fnd pir_cnt

all : ${TARGET}
CFLAGS = -lwiringPi

% : %.c
	cc -o $@ $< ${CFLAGS}



clean :
	rm ${TARGET}