#include <algorithm>

#define P_INF std::numeric_limits<double>::infinity()
#define N_INF -P_INF


template<typename T> bool intersect(const T& range1, const T& range2);
template<typename T> T intersectionNaive(const T& range1, const T& range2); //assumes the ranges intersect
template<typename T> T intersectionSafe(const T& range1, const T& range2); //may return an invalid range


class RRange {
public:
    double start = 0;
    double end = 0;

    //constructor using initializer list
    RRange(double start, double end) : start(start), end(end) {}

    double size() const;
    bool isValid() const;
    int spanType() const;
    RRange operator+(double d) const;
    RRange operator+(const RRange& other) const;
    RRange operator-(double d) const;
    RRange operator-(const RRange& other) const;
    RRange operator*(double d) const;
    RRange operator*(const RRange& other) const;
    RRange operator/(double d) const;
    RRange operator/(const RRange& other) const;
};

template<typename T> bool intersect(const T& range1, const T& range2) {
    if (range1.start >= range2.start && range1.start <= range2.end) {
        return true;
    }
    if (range2.start >= range1.start && range2.start <= range1.end) {
        return true;
    }
    return false;
}

//assume range1, range2 intersect
template<typename T> T intersectionNaive(const T& range1, const T& range2) {
    double newStart = std::max(range1.start, range2.start);
    double newEnd = std::min(range1.end, range2.end);
    return T(newStart, newEnd);
}

//return an invalid range if intersection is empty
template<typename T> T intersectionSafe(const T& range1, const T& range2) {
    if (intersect(range1, range2)) {
        return intersectionNaive(range1, range2);
    }
    else {
        return T(1, 0);
    }
}

double RRange::size() const {
    return end - start;
}

bool RRange::isValid() const {
    return (start <= end);
}

int RRange::spanType() const {
    int startSign = static_cast<int>(start >= 0);
    int endSign = static_cast<int>(end >= 0);
    return (startSign << 1) + endSign;
}

RRange RRange::operator+(double d) const {
    return RRange(start+d, end+d);
}

RRange RRange::operator+(const RRange& other) const { //pass by reference to avoid overhead
    return RRange(start+other.start, end+other.end);
}

RRange operator+(double d, const RRange& range) {
    return RRange(d+range.start, d+range.end);
}

RRange RRange::operator-(double d) const {
    return RRange(start-d, end-d);
}

RRange RRange::operator-(const RRange& other) const {
    return (other.start-end, other.end-start);
}

RRange operator-(double d, const RRange& range) {
    return RRange(d-range.end, d-range.start);
}

RRange RRange::operator*(double d) const {
    if (d >= 0) {
        return RRange(start*d, end*d);
    }
    else {
        return RRange(end*d, start*d);
    }
}

RRange RRange::operator*(const RRange& other) const {
    int thisSpanType = spanType();
    int otherSpanType = other.spanType();

    double newStart, newEnd;
    if (thisSpanType == 3 && otherSpanType == 3) {
        newStart = start * other.start;
        newEnd = end * other.end;
    }
    else if (thisSpanType == 1 && otherSpanType == 3) {
        newStart = start * other.end;
        newEnd = end * other.end;
    }
    else if (thisSpanType == 3 && otherSpanType == 1) {
        newStart = end * other.start;
        newEnd = end * other.end;
    }
    else if (thisSpanType == 0 && otherSpanType == 3) {
        newStart = start * other.end;
        newEnd = end * other.start;
    }
    else if (thisSpanType == 3 && otherSpanType == 0) {
        newStart = end * other.start;
        newEnd = start * other.end;
    }
    else if (thisSpanType == 1 && otherSpanType == 1) {
        newStart = std::min(start * other.end, end * other.start);
        newEnd = std::max(start * other.start, end * other.end);
    }
    else if (thisSpanType == 1 && otherSpanType == 0) {
        newStart = end * other.start;
        newEnd = start * other.start;
    }
    else if (thisSpanType == 0 && otherSpanType == 1) {
        newStart = start * other.end;
        newEnd = start * other.start;
    }
    else if (thisSpanType == 0 && otherSpanType == 0) {
        newStart = end * other.end;
        newEnd = start * other.start;
    }

    return RRange(newStart, newEnd);
}

RRange operator*(double d, const RRange& range) {
    if (d >= 0) {
        return RRange(d*range.start, d*range.end);
    }
    else {
        return RRange(d*range.end, d*range.start);
    }
}

RRange RRange::operator/(double d) const {
    if (d == 0) {
        return RRange(N_INF, P_INF);
    }
    else if (d > 0) {
        return RRange(start/d, end/d);
    }
    else {
        return RRange(end/d, start/d);
    }
}

RRange RRange::operator/(const RRange& other) const {
    if (other.start == 0 || other.end == 0) {
        return RRange(N_INF, P_INF);
    }

    int thisSpanType = spanType();
    int otherSpanType = other.spanType();
    if (thisSpanType == 3 && otherSpanType == 3) {
        return RRange(start/other.end, end/other.start);
    }
    else if (thisSpanType == 1 && otherSpanType == 3) {
        return RRange(start/other.start, end/other.start);
    }
    else if (thisSpanType == 0 && otherSpanType == 3) {
        return RRange(start/other.start, end/other.end);
    }
    else if (thisSpanType == 3 && otherSpanType == 0) {
        return RRange(end/other.end, start/other.start);
    }
    else if (thisSpanType == 1 && otherSpanType == 0) {
        return RRange(end/other.end, start/other.end);
    }
    else if (thisSpanType == 0 && otherSpanType == 0) {
        return RRange(end/other.start, start/other.end);
    }
    else {
        return RRange(N_INF, P_INF);
    }
}

RRange operator/(double d, const RRange& range) {
    int rangeSpanType = range.spanType();
    if (rangeSpanType == 0) {
        if (d >= 0) {
            return RRange(d/range.end, d/range.start);
        }
        else {
            return RRange(d/range.start, d/range.end);
        }
    }
    else if (rangeSpanType == 1) {
        return RRange(N_INF, P_INF);
    }
    else {
        if (range.start == 0 || range.end == 0) {
            return RRange(N_INF, P_INF);
        }

        if (d >= 0) {
            return RRange(d/range.end, d/range.start);
        }
        else {
            return RRange(d/range.start, d/range.end);
        }
    }
}
