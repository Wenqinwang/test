int maxseat = MAX;
CV seatCV;
lock seatLock;

void reserve(int n):
	seatLock.lock();
	while(numSeats<n){
		seatCV.wait(seatlock);
	}

	//reserve seats
	numSeats -= n;
	seatlock.unlock();

void cancel(int n):
	seatLock.lock();

	//return seats
	numSeats += n;
	seatCV.broadcast();
	seatLock.unlock();
