# cppCLRDLL_IP2Location
功能说明：
cpp写的IP2Location查询的CLR库，可供Net程序调用，必须和cpp的IP2Location查询dll共同使用。该库只是cpp查询库的net代理。

版本信息：
IP2Location的适用版本为DB8。VS编辑器为VS2017。

c#调用的示例代码：
using ipDll;
...
ipDll.IP2LOCCLR ip2LocLib= new IP2LOCCLR();
if (!ip2LocLib.init("E:\\Projects\\lib\\IP-COUNTRY-REGION-CITY-LATITUDE-LONGITUDE-ISP-DOMAIN.BIN")) return;
string resultStr = ip2LocLib.Query("210.69.210.100");
Console.WriteLine(resultStr);

示例代码运行结果：
country-long \t country-short \t city \t domain \t area \t latitude \t longtitude
Taiwan, Province of China       TW      Taipei  taiwan.gov.tw   Government Service Network      25.047760       121.531853
