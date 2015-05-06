/*mysql-connector-c 连接器的基本用法*/
#include <my_global.h>
#include <mysql.h>
#include <time.h>

int main(int argc, char *argv[])
{

    //获取mysql客户端的版本号
    printf("%s\n", mysql_get_client_info());

    //声明一个conn指针指向一个MYSQL结构体，这个结构体就是一个数据库连接句柄
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    int num_fields;
    int i;

    //函数mysql_init将返回一个链接句柄
    conn = mysql_init(NULL);
    if (conn == NULL) {

        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));

        exit(1);

    }

    //函数mysql_real_connect建立一个到mysql数据库的链接。调用这个函数要提供 链接句柄、主机名、用户、密码等参数，最后四个参数依次是数据库名、端口、unix套接字和客户端标志
    if (mysql_real_connect(conn, "10.10.10.91", "root", "waukeen@2014", "IP-Blacklist", 0, 0 ,0)==NULL)
    {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
    };

    //函数mysql_query执行sql语句
    if (mysql_query(
                    conn, "CREATE TABLE `list`(\
                    `id` int(11) unsigned NOT NULL AUTO_INCREMENT,\
                    `ipaddress` varchar(20) NOT NULL DEFAULT '',\
                    `weight` int(11) NOT NULL,\
                    `status` int(11) NOT NULL,\
                    `sources` varchar(20) NOT NULL DEFAULT '',\
                    `createtime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',\
                    `lasttime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,\
                    `removetime` date NOT NULL,\
                    PRIMARY KEY (`id`),\
                    UNIQUE KEY `ipaddress` (`ipaddress`)\
                    )"))
    {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
    }

    if (mysql_query(conn, "INSERT INTO `list`\
                (`ipaddress`, `weight`, `status`, `sources`, `createtime`, `removetime`)\
                VALUES ('12.12.5.62', 0, 0, '', '0000-00-00 00:00:00', '0000-00-00');"))
    {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
    }

    if (mysql_query(conn, "SELECT * FROM list"))
    {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

    //获取结果集
    result = mysql_store_result(conn);
    //获取表中的所有字段
    num_fields = mysql_num_fields(result);
    //获取表中列名称
    while((field = mysql_fetch_field(result)))
    {
        printf("%s ", field->name);

    }
    printf("\n");
    //获取每行数据，并且输出到屏幕上
    while ((row = mysql_fetch_row(result)))
    {

        for(i = 0; i < num_fields; i++)
        {

            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    //释放结果集
    mysql_free_result(result);
    //关闭链接
    mysql_close(conn);

    return 0;
}
