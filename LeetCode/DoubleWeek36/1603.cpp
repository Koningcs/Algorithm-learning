class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        a[1] = big;
        a[2] = medium;
        a[3] = small;
    }
    
    bool addCar(int carType) {
        if(a[carType] > 0) {
            a[carType] --;
            return true;
        }
        return false;
    }
private:
    int a[4];
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */