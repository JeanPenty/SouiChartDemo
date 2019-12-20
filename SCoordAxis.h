/**
* Copyright (C) 2019-2050
* All rights reserved.
*
* @file		  SCoordAxis.h
* @brief
* @version    v1.0
* @author     yiywain(��Զ)
* @date       2019/12/19
* gitee  https://gitee.com/yiywain/soui-extend.git
* Describe   ����ϵ������
*/

#pragma once
namespace SOUI
{

class SCoordAxis : public SWindow
{
	SOUI_CLASS_NAME(SChart_bar, L"CoordAxis")
public:
	SCoordAxis();
	virtual ~SCoordAxis();

	enum AXIS_TYPE{
		AXIS_LENGTHWAYS,//����
		AXIS_CROSSWISE//����
	};
	//���������ʾ�ı�
	void AddText(SStringT &Text);

	//���
	void ClearText(void);

	void SetTextByIndex(int Index,SStringT &Text);

	SStringT GetTextByIndex(int Index);

	//��������ϵ��߾�
	void SetCoordMargin(RECT &rect);

	//����������ɫ�Լ��߿�
	void SetCoord(COLORREF Color, int Width);

	//��������ϵ�̶��߳��ȿ���Լ���ɫ
	void SetCoordScale(float xLen, float yLen, int Width, COLORREF Color);

	//�����Զ�����̶ȷ�Χ ReserveValue ��Сֵ��̶���С�ľ���
	void SetAutoScope(float ReserveValue);

	//���ù̶��̶ȵķ�Χ
	void SetLockScope(float LowerValue);

	//������ʾ��С��λ��
	void SetDecimal(int Number);

	//���ÿ̶�����
	void SetScaleNumber(int Number);
	
protected:
	void OnPaint(IRenderTarget *pRT);

//	virtual CRect GetMargin(void)=0;//�ṩ���������߾�
	virtual void GetMaxMin(float &Max, float &Min)=0;

	CRect &GetDataDrawRect(void);//��ȡ���ݻ�������
	float GetValueRatio(void);

	bool NumberToScaleStr(float value, int Digit, SStringT& str);
private:
	int MeasureText(IRenderTarget *pRT, SStringT Text, int TextHeight, SIZE *size);

protected:
	SOUI_MSG_MAP_BEGIN()
		//MSG_WM_CREATE(OnCreate)
		MSG_WM_PAINT_EX(OnPaint)
	SOUI_MSG_MAP_END()

	SOUI_ATTRS_BEGIN()
		ATTR_RECT(L"CoordMargin", m_CoordMargin,TRUE)
		ATTR_INT(L"ScaleNumber", m_ScaleNumber, TRUE)	
		ATTR_FLOAT(L"LowerNumber", m_LowerValue, TRUE)
		ATTR_BOOL(L"AutoScope", m_IsAutoScope, TRUE)
		ATTR_FLOAT(L"ReserveValue", m_ReserveValue, TRUE)
		ATTR_INT(L"CoordWidth", m_CoordWidth, TRUE)
		ATTR_COLOR(L"CoordColor", m_CoordColor, TRUE)
		ATTR_FLOAT(L"XScaleLength", m_XScaleLength, TRUE)
		ATTR_FLOAT(L"YScaleLength", m_YScaleLength, TRUE)
		ATTR_COLOR(L"ScaleLineColor", m_ScaleLineColor, TRUE)
		ATTR_INT(L"ScaleLineWidth", m_ScaleLineWidth, TRUE)
		ATTR_INT(L"Decimal", m_Decimal, TRUE)
		ATTR_BOOL(L"PullOver", m_PullOver,TRUE)
		ATTR_BOOL(L"ShowOrigin", m_ShowOrigin, TRUE)
		
		ATTR_ENUM_BEGIN(L"AxisType", AXIS_TYPE, TRUE)
			ATTR_ENUM_VALUE(L"lengthways", AXIS_LENGTHWAYS)//������
			ATTR_ENUM_VALUE(L"crosswise", AXIS_CROSSWISE)//������
		ATTR_ENUM_END(m_AxisType)
	SOUI_ATTRS_END()

protected:
	CRect m_CoordMargin;

	int m_ScaleNumber;//�̶�����
	float m_LowerValue;//�̶���Сֵ
	bool m_IsAutoScope;//�Ƿ��Զ�����̶�
	float m_ReserveValue;//�Զ�����̶���Ҫһ������ֵ//֧�ְٷֱ� //���ֵ��˫���
	float m_XScaleLength;//X��̶ȳ���//֧�ְٷֱ�
	float m_YScaleLength;//Y��̶ȳ���//֧�ְٷֱ�
	COLORREF m_ScaleLineColor;//�̶�����ɫ
	int m_ScaleLineWidth;//�̶��߿��

	int m_Decimal;//С��λ
	COLORREF m_CoordColor;//��������ɫ
	int m_CoordWidth;//�����߿��
	AXIS_TYPE m_AxisType;//������
	bool m_PullOver;//С�������Ƿ񿿱�
	bool m_ShowOrigin;//�Ƿ���ʾԭ����ֵ

	//����ʱ��Ч������
	int m_XCount;
	int m_YCount;
	float m_XSignRatio;
	float m_YSignRatio;
	float m_ValueRatio;
	float m_MinValue;
	float m_MaxValue;
	float m_ValueSpace;

	SArray<SStringT> m_Text;
	CRect m_DataRect;//�����ܻ��Ƶ�����
private:
	int m_TextOffset;
};

}