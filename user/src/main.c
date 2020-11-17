/*****************************************************************************
 * 文 件 名: main.c
 * 作     者: lzj
 * 创建日期: 2020年11月16日
 * 文件描述: easylogger 测试
 * 其     他: 
 * 修改日志: 
*****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LOG_TAG "main"

#include "elog.h"



/*****************************************************************************
 * 函 数 名: elog_init_config
 * 创 建 人: lzj
 * 创建日期: 2020年11月17日
 * 函数功能: elog配置和初始化
 * 输入参数: void  无
 * 返 回 值: 无
 * 其     它:  
*****************************************************************************/
void elog_init_config(void)
{
    setbuf(stdout, NULL);

    elog_init();    // 初始化elog
    elog_set_text_color_enabled(true);  // 使能文本颜色设置
    
    /* 设置每个级别的日志输出格式 */
    elog_set_fmt(ELOG_LVL_ASSERT,  ELOG_FMT_ALL);                    // 输出所有内容
    elog_set_fmt(ELOG_LVL_ERROR,   ELOG_FMT_LVL | ELOG_FMT_TAG);     // 输出日志级别信息和日志TAG
    elog_set_fmt(ELOG_LVL_WARN,    ELOG_FMT_LVL | ELOG_FMT_TAG);     // 输出日志级别信息和日志TAG
    elog_set_fmt(ELOG_LVL_INFO,    ELOG_FMT_LVL | ELOG_FMT_TAG);     // 输出日志级别信息和日志TAG
    elog_set_fmt(ELOG_LVL_DEBUG,   ELOG_FMT_ALL & ~(ELOG_FMT_TIME | ELOG_FMT_P_INFO | ELOG_FMT_T_INFO));      // 除了时间、进程信息、线程信息之外，其余全部输出
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL);                    // 输出所有内容

    elog_start();   // 启动elog
}


/*****************************************************************************
 * 函 数 名: main
 * 创 建 人: lzj
 * 创建日期: 2020年11月17日
 * 函数功能: 主函数
 * 输入参数: void  无
 * 返 回 值: 无
 * 其     它:  
*****************************************************************************/
int main(void)
{
    elog_init_config();
    int i=0;

    while(1)
    {
        log_a("hello elog! i = %d\n", i);
        log_e("hello elog! i = %d\n", i);
        log_w("hello elog! i = %d\n", i);
        log_i("hello elog! i = %d\n", i);
        log_d("hello elog! i = %d\n", i);
        log_v("hello elog! i = %d\n", i);
        sleep(5);
        i++;
    }
    return 0;
}


