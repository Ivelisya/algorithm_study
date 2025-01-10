#if 0
class SnapshotArray {
public:
    SnapshotArray(int length):snap_cnt(0),history(length) {
    }

    void set(int index, int val) {
        history[index].emplace_back(snap_cnt,val);
    }

    int snap() { 
        return snap_cnt++;
    }

    int get(int index, int snap_id) {
        auto x = upper_bound(history[index].begin(), history[index].end(), pair{snap_id + 1, -1});
        return x == history[index].begin() ? 0 : prev(x)->second;

    }
private:
    int snap_cnt;
    vector<vector<pair<int,int>>> history;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
#endif