/**
* Copyright (C) 2019-2050
* All rights reserved.
*
* @file       SLineChart.h
* @brief
* @version    v1.0
* @author     yiywain(��Զ)
* @date       2019/12/19
* gitee  https://gitee.com/yiywain/soui-extend.git
* Describe    ����ͼ����ͼ
*/

#pragma once
#include "SCoordAxis.h"

namespace SOUI
{

	class SLineChart :
		public SCoordAxis
	{
		SOUI_CLASS_NAME(SChart_bar, L"LineChart")
	public:
		struct LineTag
		{
			SStringT Name;
			SArray<float> Values;
			COLORREF Color;
			LineTag()
			{
				Name = L"";
				Color = RGBA(0, 0, 0, 255);
			}
			LineTag(SStringT Name, SArray<float> &Values, COLORREF Color)
			{
				this->Name = Name;
				this->Values = Values;
				this->Color = Color;
			}
		};

		SLineChart();
		~SLineChart();

		//����һ����
		void CreateLine(int id, SStringT Name, COLORREF Color);

		//�����������
		void AddData(int id, float Value);

		//�����������
		void Clear();

		//�޸��ߵ�����
		void SetLineData(int id, LineTag &LineData);

		//��ȡ�ߵ�����
		LineTag &GetLineData(int id);

		void SetLineValue(int id, int index, float Value);

		//�����߿�
		void SetLineWidth(int Width);

		//�������͸��ͨ�� ������ͼ��Ч
		void SetFillRect(int Alpha);

		//�������ݵ�������� ֧�ְٷֱ�
		void SetDataEnd(float End);

		//�����Ƿ�Ϊ����ͼ
		void SetCurveChart(bool Curve);

		void PopTopPushBack(int id, float Value);

		void UpdateWindow()
		{
			InvalidateRect(&GetClientRect());
		}
	protected:
		virtual void GetMaxMin(float &Max, float &Min);

		void OnPaint(IRenderTarget *pRT);
		void OnMouseMove(UINT nFlags, CPoint point);
		void OnMouseLeave();
	protected:
		SOUI_MSG_MAP_BEGIN()
			MSG_WM_PAINT_EX(OnPaint)
			MSG_WM_MOUSEMOVE(OnMouseMove)
			MSG_WM_MOUSELEAVE(OnMouseLeave)
			SOUI_MSG_MAP_END()

			SOUI_ATTRS_BEGIN()
			ATTR_COLOR(L"LineColor", m_LineColor, TRUE)
			ATTR_INT(L"LineWidth", m_LineWidth, TRUE)
			ATTR_INT(L"FillRect", m_FillRect, TRUE)
			ATTR_FLOAT(L"DataEnd", m_DataEnd, TRUE)
			ATTR_BOOL(L"IsCurve", m_IsCurve, TRUE)
			ATTR_INT(L"DataPointSize", m_DataPointSize, TRUE)
			ATTR_COLOR(L"DataPointCentreColor", m_DataPointCentreColor, TRUE)

			ATTR_BOOL(L"CursorTip", m_CursorTip, TRUE)
			ATTR_FONT(L"CursorTipFont", m_CursorTipFont, TRUE)
			ATTR_COLOR(L"CursorTipTextColor", m_CursorTipTextColor, TRUE)
			ATTR_COLOR(L"CursorTipColorBkgnd", m_CursorTipColorBkgnd, TRUE)

			ATTR_COLOR(L"CursorLineColor", m_CursorLineColor, TRUE)
			ATTR_INT(L"CursorLineWidth", m_CursorLineWidth, TRUE)
			SOUI_ATTRS_END()
	protected:
		COLORREF m_LineColor;
		int m_LineWidth;
		int m_FillRect;//�������͸��ͨ�� 0Ϊ�����0-255
		float m_DataEnd;//���ݽ���λ�� 0Ϊ������ ֧�ְٷֱ�
		bool m_IsCurve;//�Ƿ������� �����ݲ�֧���������

		INT m_DataPointSize;//���ݵ��С
		COLORREF m_DataPointCentreColor;//���ݵ���ɫ

		BOOL m_CursorTip; //�Ƿ���Ӧ���
		SDpiAwareFont m_CursorTipFont;//�����ʾ����
		COLORREF m_CursorTipTextColor;//�����ʾ������ɫ
		COLORREF m_CursorTipColorBkgnd;
		COLORREF m_CursorLineColor;
		INT m_CursorLineWidth;

		typedef SMap<int, LineTag> CoordLineData;
		CoordLineData m_Data;
	private:
		bool m_CursorInCoord;
		CPoint m_CursorPoint;
	};

}