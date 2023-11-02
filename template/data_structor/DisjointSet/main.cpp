class DisJointSet {
public:
    DisJointSet(int n);
    virtual ~DisJointSet();

    void join(int x, int y);
    bool testJoin(int x, int y);

private:
    int _getFather(int pos);
    std::vector<int> fathers;
};

DisJointSet::DisJointSet(int n) {
    fathers.resize(n);
    for (int i = 0; i < n; i++) {
        fathers[i] = i;
    }
}
DisJointSet::~DisJointSet() {
}

void DisJointSet::join(int x, int y) {
    fathers[_getFather(x)] = _getFather(y);
}

bool DisJointSet::testJoin(int x, int y) {
    return _getFather(x) == _getFather(y);
}

int DisJointSet::_getFather(int pos) {
    if (fathers[pos] == pos) {
        return pos;
    }
    fathers[pos] = _getFather(fathers[pos]);
    return fathers[pos];
}