//
// Created by zp on 17-7-21.
//

#ifndef UCL_CPP_GENZCPSPROPERTY_H
#define UCL_CPP_GENZCPSPROPERTY_H

#include "../base/UCLPropertyBase.h"

/*
 * ZCPS:
 */
class GenZCPSProperty {
public:
    //目标对象名称
    static UCLPropertyBase genName(string vPart, uint8_t helper=0);

    //空间位置信息, 默认解析规则为GPS
    /**
     *
     * @param vPart
     * @param parse 坐标体系描述位置信息规则
     * 0001 表示采用中国北斗卫星导航系统（BDS）坐标体系描述位置信息；
     * 0010 表示采用全球定位系统（GPS）坐标体系描述位置信息；
     * 默认为2
     * @param helper
     * @return
     */
    static UCLPropertyBase genSpaceLoc(string vPart, uint8_t parse=2, uint8_t helper=0);

    //时间信息, 默认为GPS授时时间
    /**
     *
     * @param vPart
     * @param parse 授时信息规则
     * 0001表示采用中国北斗卫星导航系统（BDS）授时信息；
     * 0010表示POSIX时间标准时间；
     * 默认为2
     * @param helper
     * @return
     */
    static UCLPropertyBase genTime(string vPart, uint8_t parse=2, uint8_t helper=0);

    /*
    目标外形包括几何轮廓，投影边界两部分，以西文分隔符“;”分割，必须有一个";",若某部分为空该部分可省略，但逗号必须：
    第一部分几何轮廓，根据受控映射表进行取值；
    第二部分投影边界，空间位置坐标集合。
                                                                                 */
    static UCLPropertyBase genShape(string vPart, uint8_t helper=0);

    /*
    物理特性包括了电磁特性，声波特性和核生化特性三部分，以西文分隔符“;”分割，，必须有三个";",若某部分为空该部分可省略，但逗号必须：
    第一部分电磁特性，根据电磁特性受控映射表进行取值；
    第二部分声波特性，根据声波特性受控映射表进行取值；
    第三部分核生化特性，根据核生化特性受控映射表进行取值。
    第四部分雷达特性，根据雷达特性受控映射表进行取值。
                                                                                                                                       */
    static UCLPropertyBase genPhysical(string vPart, uint8_t helper=0);

    //目标材质
    static UCLPropertyBase genMaterial(string vPart, uint8_t helper=0);

    //通过程度
    static UCLPropertyBase genPassingAbility(string vPart, uint8_t helper=0);

    //空间敌我态势(Space Enemy Situation)
    /*
    空间状况信息地面敌我状况信息，空中敌我状况信息和水下敌我状况信息三个部分，以西文分隔符“;”分割，必须有两个";",若某部分为空该部分可省略，但逗号必须：
    第一部分地面敌我状况信息；
    第二部分空中敌我状况信息；
    第三部分水下敌我状况信息。
                                                                                  */
    static UCLPropertyBase genSpaceEnemyS(string vPart, uint8_t helper=0);

    /*
     * 绝对运动特性
     * 默认规则为：m/s, m/s*s
     * 绝对运动特性包括绝对速度，绝对加速度，运行轨迹三部分，以西文分隔符“;”分割，必须有两个";",若某部分为空该部分可省略，但逗号必须：
     * 第一部分绝对速度为数值；
     * 第二部分绝对加速度为数值；
     * 第三部分运行轨迹为坐标集合。
                                                                                                 */
    static UCLPropertyBase genAbsMotionFea(string vPart, uint8_t parse=1, uint8_t helper=0);

    /*
     * 相对运动特性
     * 默认规则为：m/s, m/s*s
     * 相对运动特性包括绝对速度，绝对加速度，运行轨迹三部分，以西文分隔符“;”分割，必须有两个";",若某部分为空该部分可省略，但逗号必须：
     * 第一部分绝对速度为数值；
     * 第二部分绝对加速度为数值；
     * 第三部分运行轨迹为坐标集合。
    */
    static UCLPropertyBase genRelMotionFea(string vPart, uint8_t parse=1, uint8_t helper=0);

    //运行轨迹, 默认解析规则为GPS
    /**
     *
     * @param vPart
     * @param parse
     * 0001表示采用中国北斗卫星导航系统（BDS）坐标体系描述位置信息；
     * 0010表示采用全球定位系统（GPS）坐标体系描述位置信息；
     * 默认规则为GPS
     * @param helper
     * @return
     */
    static UCLPropertyBase genTravellingPath(string vPart, uint8_t parse=2, uint8_t helper=0);

    static UCLPropertyBase genBoundingBox(string vPart, uint8_t helper=0);
};


#endif //UCL_CPP_GENZCPSPROPERTY_H