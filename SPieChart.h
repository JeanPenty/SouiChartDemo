/**
* Copyright (C) 2019-2050
* All rights reserved.
*
* @file       SPieChart.h
* @brief
* @version    v1.0
* @author     yiywain(��Զ)
* @date       2019/12/19
* gitee  https://gitee.com/yiywain/soui-extend.git
* Describe    ��ͼ
*/

#pragma once

#include <string>
#include <vector>
namespace SOUI
{
	class SPieChart;
	typedef struct _tagPie
	{
		friend SPieChart;
		float		Value;
		COLORREF	Color;
		SStringT StrTip;

		_tagPie(){
			Value = 0;
			Color = RGB(0, 0, 0);
			StrTip = L"��";
		}
		_tagPie(float Value, COLORREF color, const SStringT& strTip){
			this->Value = Value;
			this->Color = color;
			this->StrTip = strTip;
		}
	private:
		int id;
	}PIE;


	typedef std::vector<PIE>	PIES;

	//��ͼ�ؼ� ֧��ʵ�ı�ͼ ���ı�ͼ õ��ͼ
	class SPieChart : public SWindow
	{
		SOUI_CLASS_NAME(SPieChart, L"PieChart")
	public:
		SPieChart(void);
		~SPieChart(void);

		void SetSeriesName(LPCTSTR Name);
		//�������
		int AddPie(PIE &TagPie);

		//�����������
		void Clear();

		//�޸ı�ͼ
		void SetPie(int id, PIE &TagPie);

		//�Ƴ�����һ����������
		void RemoveSectorById(int Id);

		//ͨ��id��ȡ��ͼ����
		PIE* GetSectorById(int Id);

		//���ñ�ͼ����ڿؼ��Ĵ�С����Ϊ�ٷֱ�
		void SetPieSize(float Width);

		//���εݼ���С�İ뾶�����뾶�ı�ֵ  �Ƽ�0.5
		void SetSectorMin(float Decrease = 0.5);

		//���ÿ���Բ��С
		void SetHollow(float Size, bool ShowHollowText = true);
		void UpdateWindow()
		{
			InvalidateRect(&GetClientRect());
		}
	protected:

		void OnPaint(IRenderTarget *pRT);
		void OnMouseMove(UINT nFlags, CPoint point);
		void OnMouseLeave();

	private:

	protected:
		SOUI_MSG_MAP_BEGIN()
			MSG_WM_PAINT_EX(OnPaint)
			MSG_WM_MOUSEMOVE(OnMouseMove)
			MSG_WM_MOUSELEAVE(OnMouseLeave)
			SOUI_MSG_MAP_END()

			SOUI_ATTRS_BEGIN()
			ATTR_FLOAT(L"PieSize", m_PieSize, TRUE)

			ATTR_BOOL(L"ShowTip", m_ShowTip, TRUE)
			ATTR_INT(L"TipLineLen", m_TipLineLen, TRUE)
			ATTR_FONT(L"TipFont", m_TipFont, TRUE)
			ATTR_COLOR(L"TipColor", m_TipColor, TRUE)

			ATTR_BOOL(L"CursorTip", m_CursorTip, TRUE)
			ATTR_COLOR(L"CursorTipColorBkgnd", m_CursorTipColorBkgnd, TRUE)
			ATTR_INT(L"CursorEnlargeRadius", m_CursorEnlargeRadius, TRUE)
			ATTR_FONT(L"CursorTipFont", m_CursorTipFont, TRUE)
			ATTR_COLOR(L"CursorTipTextColor", m_CursorTipTextColor, TRUE)

			ATTR_BOOL(L"Decimal", m_Decimal, TRUE)
			ATTR_STRINGT(L"SeriesName", m_SeriesName, TRUE)
			ATTR_FLOAT(L"Decrease", m_Decrease, TRUE)

			ATTR_FLOAT(L"HollowSize", m_HollowSize, TRUE)
			ATTR_BOOL(L"ShowHollowText", m_ShowHollowText, TRUE)
			ATTR_FONT(L"HollowFont", m_HollowTextFont, TRUE)
			ATTR_COLOR(L"HollowTextColor", m_HollowTextColor, TRUE)
			SOUI_ATTRS_END()
	protected:
		PIES		m_VecPies;

		float m_PieSize;//Բ�Ĵ�С ����Ϊ�ٷֱ�

		bool m_ShowTip; //�Ƿ���ʾ��ʾ�ı�
		int m_TipLineLen;//����ʾ���߳���
		SDpiAwareFont m_TipFont;//��ʾ����
		COLORREF m_TipColor;//��ʾ����������ɫ (Ĭ��Ϊ��ͼ��ɫ)

		bool m_CursorTip;//�Ƿ���Ӧ���
		COLORREF m_CursorTipColorBkgnd;//��ʾ�򱳾���ɫ
		int m_CursorEnlargeRadius;//���ѡ�еķŴ�뾶
		SDpiAwareFont m_CursorTipFont;//�����ʾ����
		COLORREF m_CursorTipTextColor;//�����ʾ������ɫ

		int m_Decimal;//������ʾ��С��λ��
		SStringT m_SeriesName;//ϵ������

		//õ��ͼ
		float m_Decrease;//�ٷֱȲ��� ���һ���������һ�����α�

		//���ı�ͼ
		float m_HollowSize;//����Բ��С ����ֵ�Ͱٷֱ�
		bool m_ShowHollowText;//�Ƿ���ʾ�п����� m_HollowSize>0��Ч
		SDpiAwareFont m_HollowTextFont;//��������
		COLORREF m_HollowTextColor;//����������ɫ (Ĭ��Ϊ��ͼ��ɫ)
	private:
		bool m_CursorInPie;
		float m_Sum;
		CPoint m_CursorPoint;
	};
}