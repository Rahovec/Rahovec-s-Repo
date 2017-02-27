struct daily{
	int maf; //can
	int consumption; // can
	int rpm; //can
	float obd_speed; //can
	float gps_speed; //gps
};

struct drag{
	int rpm;
	float obd_speed;
	float gps_speed;
	float accel; //0-100 gps/obd speed avr
/*can be float*/	int sixty_ft; //60ft gps + time
};

struct race{
	float obd_speed;
	float gps_speed;
	float g_force; //9axis
	int throttle_pos; //can
	long lap_time //gps
};

struct drift{
	float obd_speed;
	float gps_speed;
	int turn_vector; //9 axis somehow ... not shure if int
	int turn_rotation //9axis yaw pitch roll ...
};
