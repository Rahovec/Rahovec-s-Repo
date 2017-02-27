struct daily{
	float maf; //can
	float consumption; // can
	int rpm; //can
	float speed; //(obd + gps)/2
};

struct drag{
	int rpm;
	float speed;
	float accel; //0-100 gps/obd speed avr
	float sixty_ft; //60ft gps + time /*can be float*/	
	float quarter; //quarter mile
};

struct race{
	float speed;
	float g_force; //9axis
	int throttle_pos; //can
	long lap_time //gps
};

struct drift{
	float speed;
	int turn_vector; //9 axis somehow ... not shure if int
	int turn_rotation //9axis yaw pitch roll ...
};
/////////////////////////////////////////////////////
struct daily{
	int maf; //can
	int consumption; // can
	int rpm; //can
	float obd_speed; //(obd + gps)/2
};

struct drag{
	int rpm;
	float obd_speed;
};

struct race{
	float obd_speed;
};

struct drift{
	float obd_speed;
};
