#pragma once
#include "pch.h"

ref class CAD {
public:
	CAD(void);
	DataSet^ getRows(String^, String^);
	void actionRows(String^);
private:
	String^ _connectionString;
	String^ _requestSql;
	SqlConnection^ _sqlConnection;
	SqlDataAdapter^ _sqlDataAdapter;
	SqlCommand^ _sqlCommand;
	DataSet^ _dataSet;
	void setSql(String^);
};

