#include <microsim/cfmodels/MSCFModel_ModifiedKrauss.h>
#include <utils/options/OptionsCont.h>

MSCFModel_ModifiedKrauss::MSCFModel_ModifiedKrauss(const MSVehicleType* vtype) :
    MSCFModel(vtype), myDecel(vtype->getCarFollowModelDecel()), myTau(1.0) {}

double MSCFModel_ModifiedKrauss::_vSafe(double speed, double gap, double predSpeed) const {
    const double b = myDecel;          // 最大减速度（4.5 m/s²）
    const double Gamma = 1.0;          // 反应时间（1秒）
    const double Ti = 2.0;             // 加速度渐变时间（假设值）
    const double vl = predSpeed;       // 前车速度
    const double s = gap;              // 车间距

    // 公式（8）实现
    double term = pow(b * (Gamma + Ti), 2) + 2 * b * s + pow(vl + (b * Ti)/2, 2);
    double vs = -b * (Gamma + Ti) + sqrt(term);
    return vs;
}

double MSCFModel_ModifiedKrauss::finalizeSpeed(double vSafe, double vIntended, double vCurrent) {
    return MIN3(vSafe, vIntended, vCurrent + ACCEL2SPEED(myAccel));
}