class UndergroundSystem {
public:
    unordered_map <int, int>        entringTime;
    unordered_map <int, string>     entringStation;
    unordered_map <string, int>     journeyCnt;
    unordered_map <string, int>     journeyTime;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        entringTime[id] = t;
        entringStation[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        string journey = entringStation[id] + "+" + stationName;
        journeyCnt[journey]++;
        journeyTime[journey] += t-entringTime[id];
        
        // cout << journey << " " << journeyCnt[journey] << " " << journeyTime[journey] << endl;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string journey = startStation + "+" + endStation;
        return ((double)journeyTime[journey]/journeyCnt[journey]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */