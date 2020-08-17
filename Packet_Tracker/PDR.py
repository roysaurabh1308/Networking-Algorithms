import xlrd
file_location="Packet.xlt"
workbook=xlrd.open_workbook(file_location)
sheet=workbook.sheet_by_index(0)
total_packet=0
col=0
p=0
count=0
rows=sheet.nrows
print("total number of rows in table=%d"%rows)
count0=0
for i in range(1,rows):
	if sheet.cell(i,0).value==0 and sheet.cell(i,7).value=="NODE-6":
		count0=count0+1
	continue
	
print(count0)
print("Total Number of packets generated=%d"%max(sheet.col_values(col,start_rowx=1,end_rowx=rows)))
for i in range(1,rows):
	if sheet.cell(i,7).value=='NODE-6':
		count=count+1
	continue

count=count-count0
p=count/max(sheet.col_values(col,start_rowx=1,end_rowx=rows))*100
print("Total Number of Packet Received=%d"%count)

print("Data Throughput in percentage=%d"%p)

