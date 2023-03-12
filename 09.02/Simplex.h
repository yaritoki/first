#pragma once

#include "stdafx.h""
#include "SimplexOps.h"
#include <array>
namespace OptLib  // ����� ��� �������� "������ �����"
{
	template <size_t dim>//dim -��������
	using Point = std::array <double, dim>;//��������� ������� �������� ������ � ������� 8 ���� 
	// ����� ��� ��������� ��� ���� ����� ����� ���� ��������� ��� ������� Point<7> p; - ����� � 7-�� ������ ������������


	template <size_t dim>                                                  // �������� ������ ����� �����, ������ ���� ����� , ����������� ������, ����������� ������ 
	//��������a
	Point<dim> operator + (const Point<dim>& p1, const Point<dim>& p2)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::plus<>{});
		return result;
	}

	//��������
	// ���������
	template <size_t dim>
	Point<dim> operator - (const Point<dim>& p1, const Point<dim>& p2)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::minus<>{});
		return result;
	}																																//��������

	template <size_t dim>
	Point<dim> operator * (const Point<dim>& p1, const Point<dim> p2)
	{
		Point<dim> result;

		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::multiplies<>{});

		return result;
	}

	//�������
	template <size_t dim>
	Point<dim> operator / (const Point<dim>& p1, const Point<dim>& p2)
	{
		Point<dim> result;

		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), SimplexOps::BinaryOps::del<>{});

		return result;
	}

	//��������� ���������
	template <size_t dim>
	double sc(const Point<dim>& p1, const Point<dim>& p2)															//������������� ��������� ������������
	{
		Point<dim> result;
		double res = 0;
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::multiplies<>{});
		for (auto& el : result)
			res += el;
		return res;
	}

	/*��������� �� �����*/
	template <size_t dim>
	Point<dim> operator * (const Point<dim>& p1, double scalar)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::mult<double>{scalar});
		return result;
	}
	template <size_t dim>
	Point<dim> operator * (double scalar, const Point<dim>& p1)
	{
		return p1 * scalar;
	}

	//������� ����� �� ����� � �� ������
	template <size_t dim>
	Point<dim> operator / (const Point<dim>& p1, double scalar)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::del<double>{scalar});
		return result;
	}
	template <size_t dim>					//�������� ������ ��������� �����
	Point<dim> operator / (double scalar, const Point<dim>& p1)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::del1<double>{scalar});
		return result;
	}


	//�������� ����� � �����
	template <size_t dim>
	Point<dim> operator + (const Point<dim>& p1, double scalar)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::plus<double>{scalar});
		return result;
	}
	template <size_t dim>
	Point<dim> operator + (double scalar, const Point<dim>& p1)
	{
		return p1+ scalar;
	}


	//��������� ����� � �����
	template <size_t dim>
	Point<dim> operator - (const Point<dim>& p1, double scalar)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::minus<double>{scalar});
		return result;
	}
	template <size_t dim>
	Point<dim> operator - (double scalar, const Point<dim>& p1)
	{
		Point<dim> res =p1* -1;
		return res+ scalar;
	}

	//������
	template <size_t dim>
	Point<dim>  Abs(const Point<dim>& p1)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::abs{});
		return result;
	}

	/*������*/
	template <size_t dim>
	Point<dim>  Sqrt(const Point<dim>& p1)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::sqrt{});
		return result;
	}

	


	//16.02
	template <size_t dim>
	struct RawPoint
	{
		RawPoint() = default;
		Point<dim> P;
		RawPoint(const Point<dim>& p) :P{ p } {};
		RawPoint(Point<dim>&& p) :P{ std::move(p) } {};
		double operator [](size_t i)const
		{
			return P[i];
		}
		operator Point<dim>()
		{
			return P;
		};
	};
	template <size_t dim>
	struct PointVal :public RawPoint<dim>
	{
		double val;
		PointVal() = default;
		//PointVal(const PointVal& p) = default;
		PointVal(Point<dim>&& p, double val) :RawPoint<dim>{ std::move(p) }, val{ val }{};
		PointVal(const Point<dim>& p, double val) :RawPoint<dim>{ p }, val{ val }{};

		bool operator<(const Point<dim>& rhs)
		{
			return this->val < rhs.val;
		}
	};

	//20.02
	template<size_t count, typename point>
	using SetOfPoints = std::array<point, count>;
	//����������������
	//point ::Dim
	//static constexpr size_t Dim = dim;


	template<size_t count, typename point>
	auto Tr(const SetOfPoints<count, point>& rhs)
	{
		SetOfPoints<count, point> Res ;

		for (size_t i = 0; i < count; i++)
		{
			for (size_t j = 0; j < count; j++)//��� ����������
			{
				Res[i][j] = rhs[j][i];
			}

		}

		return Res;
	}


	

	template<size_t count, typename point>
	point operator*(const SetOfPoints<count, point>& rhs, const point& ihs)
	{
		point res;
		for (size_t i = 0; i < count; i++)
		{
			res[i] = sc(rhs[i], ihs);
		}
		
		return res;
	}
	template<size_t count, typename point>
		SetOfPoints<count,point> operator*(const SetOfPoints<count, point>& rhs, const SetOfPoints<count, point>& ihs)
	{
			SetOfPoints<count, point> Res;
			
		for (size_t i = 0; i < count; i++)
		{
			
				Res[i] = rhs * ihs[i];
		
		}
		Res=Tr(Res);

		return Res;
	}







		//27.02
	template <size_t count, typename point> 
	class RawSetOfPoints
	{
	protected:
		SetOfPoints<count, point> ItsSetOfPoints;
	public:
		RawSetOfPoints() = default;
		RawSetOfPoints(SetOfPoints<count,point>&&s):ItsSetOfPoints{std::move(s)}{}//move "�����" ������ �� ���������
		RawSetOfPoints(SetOfPoints<count, point>& sop) :ItsSetOfPoints{ sop } {}


		 point operator [](size_t i) const
		{
			//assert(i < count);// �� ���� �������� ��� ������ ������ �������(�������� � ������ ������ � �� �� ����� ������ ����)
			return Points()[i];
		}
			

		 const SetOfPoints<count, point>& Points()const { return ItsSetOfPoints; }
		point Mean()const
		{
			point res{ Points()[0] };
			if constexpr (count > 1)
			{
				for (size_t i = 1; i < count; i++)
				{
					res =res+ ItsSetOfPoints[i];
				}
				res =res / static_cast<double>(count);
			}
			return res;
		}
			  operator SetOfPoints<count, point>() { return Points(); }

		point Disp()const
		{
			point sr = Mean();
			point di = (ItsSetOfPoints[0]-sr)* (ItsSetOfPoints[0] - sr);
			for (size_t i = 1; i < count; i++)
			{
				di = di + (ItsSetOfPoints[i] - sr) * (ItsSetOfPoints[i] - sr);
			}
			di = di / count;
			return di;
		}

	};

			
	template <size_t count, typename point,typename pointval>
	class SetOfPointsVal : public RawSetOfPoints < count, pointval>
	{
		
	public:
		SetOfPointsVal() = default;
		SetOfPointsVal(SetOfPoints<count, pointval>&& s) :RawSetOfPoints<count,pointval>{ std::move(s) } {}
		SetOfPointsVal(SetOfPoints<count, point>&& s, std::array<double,count>&&Pval) :
			SetOfPointsVal<count, point, pointval>{std::move(make_field(std::move(s),std::move(Pval)))}{}

		static SetOfPoints<count, pointval> make_field(SetOfPoints<count, point>&& s,
			std::array<double, count>&& vals)
		{
			SetOfPoints <count, pointval> P;
			//���� � ������ ����� �������� �����������
			for (size_t i=0;i<count;i++)
			{
				P[i] = pointval{ s[i],vals[i] };
			}
			return P;			
		}
	};
	
	/*
	template<size_t count/*,class*, typename point, typename pointval>//���������� �� ��������
	class SetOfPointsValsSort : public SetOfPointsVal<count, point, pointval>
	{
	private :
		void sort()
		{
			std::sort();
		}
	public:
		SetOfPointsValSort(SetOfPoints<count,pointval>&&s):
			SetOfPointsVal<count, point, pointval>{ std::move(s) } {this->Sort(); }
		SetOfPointsValSort(SetOfPoints<count,point>&&s,std::array<double,count>&& vals)
			:SetOfPoints < count, point>{ std::move(s) },PointVal<count>{std::move(vals)}



	};

	*/


		
















		
}

//����� � ����� ��������



/*
sqrt		��������
abs			��������
���������	��������
p1*p1		��������
p1+p2		��������
p1+bouble	��������
p1-p2		��������
p1/double	��������
p1/p2		
p1*double	 ��������





*/	
		






//*-/ ��������� �� ����� ������� �� �����






//���� �� ��� �����
/*
class Point
{
Point<dim> operator +(const Point&p1,const Point&p2);
����� ��� �������� ��������
}
*/



// �� ��� ��������� ������ ���� � ������
/*

���������� ��������� ������ � ����� � ������ ����� �����
� ������ ���������� ���������� 
� ��� �������� 
*/
