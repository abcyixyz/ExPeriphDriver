/******************************************************************************/
/** ģ�����ƣ���չ��������                                                   **/
/** �ļ����ƣ�hlpmfunction.h                                                 **/
/** ��    ����V1.0.0                                                         **/
/** ��    �飺ʵ��PM25���⴫����HLPM025K3�����ݶ�ȡ                          **/
/**           (1)�����ʣ�9600bit/S;����λ:8λ;ֹͣλ:1λ;У��λ:��           **/
/**           (2)���ݷ��ͼ��ʱ��Ϊ0.8��1.2S���룩                           **/
/**           (3)���ݸ�ʽ��7���ֽ�                                           **/
/**             +------+--------+--------+-------+-------+------+------+     **/
/**             |��ʼλ|PM2.5(H)|PM2.5(L)|PM10(H)|PM10(L)|У��λ|����λ|     **/
/**             +------+--------+--------+-------+-------+------+------+     **/
/**             | 0xAA | 1�ֽ�  | 1�ֽ�  | 1�ֽ� | 1�ֽ� | 1�ֽ�| 0xFF |     **/
/**             +------+--------+--------+-------+-------+------+------+     **/
/**               ����У��λ=PM2.5(H)+PM2.5(L)+PM10(H)+PM10(L)               **/
/**           (4)���ݴ��������յ������ݰ���ʽ�����õ�PM2.5��PM10��ֵ��     **/
/**               PM2.5=(PM2.5(H)��256+PM2.5(L))��0.1                          **/
/**               PM10=(PM2.5(H)��256+PM2.5(L))��0.1                           **/
/**--------------------------------------------------------------------------**/
/**ʹ��˵����                                                                **/
/**    1�����ô���ͨѶ��������յ���Ϊ7���ֽڳ������ݣ��򴫸�ParsingPMData�� **/
/**       ��������ͬʱ�����ս���ı�������Ϊ2�������������飬�Բ�����ʽ����  **/
/**       ParsingPMData��������һ��Ԫ��ΪPM2.5����,�ڶ���Ԫ��ΪPM10���ݡ�    **/
/**--------------------------------------------------------------------------**/
/** �޸ļ�¼��                                                               **/
/**     �汾      ����              ����              ˵��                   **/
/**     V1.0.0  2013-07-28          ľ��              �����ļ�               **/
/**                                                                          **/
/******************************************************************************/ 

#ifndef __HLPMFUNCTION_H
#define __HLPMFUNCTION_H

#include "stdbool.h"
#include "stdint.h"

#ifndef HLPMRxBufferLength
#define HLPMRxBufferLength 35
#endif

/*����HLPM025K3��������*/
typedef struct HlpmObject {
  float pm25;   //PM2.5����ֵ
  float pm100;  //PM10����ֵ
  struct HlpmRxBuffer{
    uint8_t queue[HLPMRxBufferLength];  //��ֵ�洢����
    uint8_t pRead;      //������ָ��
    uint8_t pWrite;     //д����ָ��
    uint16_t (*DeQueue)(struct HlpmObject *hlpm,uint8_t *rxBuf);        //���Ӳ���
    void (*EnQueue)(struct HlpmObject *hlpm,uint8_t rData);             //��Ӳ���
  }rxBuffer;    //������ջ������
}HlpmObjectType;

/*����PM2.5��PM10������*/
bool ParsingPMData(HlpmObjectType *hlpm);

/*HLPM�����ʼ������*/
void HlpmInitialization(HlpmObjectType *hlpm);
#endif
/*********** (C) COPYRIGHT 1999-2019 Moonan Technology *********END OF FILE****/