// di - dependency injections
// http://www.boost.org/doc/libs/1_43_0/libs/python/doc/v2/register_ptr_to_python.html
// Danger: http://stackoverflow.com/questions/20825662/boost-python-argument-types-did-not-match-c-signature

#include "design/preamplifiers_hieracrhy.h"

// Third party
#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using boost::shared_ptr;

TEST(DI, Base) {
	//Preamplifier preampl;  // �� �������������
	//PreamplifierImplFake preampl;
	PreamplifierImplReal preampl;  // �������� �� ��������!

	// ���������� ���
	// �������� ��� ����������
	preampl.SetChannel(1);
}

TEST(DI, SmartPtr) {
	//Preamplifier preampl;  // �� �������������
	//PreamplifierImplFake preampl;
	shared_ptr<Preamplifier> preampl(new PreamplifierImplFake());  // �������� �� ��������!

	// ���������� ���
	// �������� ��� ����������
	preampl->SetChannel(1);
}
