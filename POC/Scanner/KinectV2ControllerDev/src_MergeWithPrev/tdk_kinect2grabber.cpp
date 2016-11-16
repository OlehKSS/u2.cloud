#include "tdk_kinect2grabber.h"

//#include <Kinect.h>

//default constructor

TDK_Kinect2Grabber::TDK_Kinect2Grabber()
{
    mv_imageViewer = boost::make_shared<pcl::visualization::ImageViewer>("TDK image viewer");
    //mv_cloudViewer = boost::make_shared<pcl::visualization::PCLVisualizer>("TDK cloud viewer");
    //PSP

    //start the grabber
    mv_grabber = boost::make_shared<pcl::Kinect2Grabber>();

    // Register Callback Function
    boost::signals2::connection connection = mv_grabber->registerCallback( mv_pointCloudCallback );
    mv_grabber->start();

}

void TDK_Kinect2Grabber::mf_getPointCloudFrame(pcl::PointCloud<PointType>::Ptr &cloud)
{
    boost::mutex::scoped_try_lock lock( mv_mutex );
    cloud = mv_cloud;
}

void TDK_Kinect2Grabber::mf_closeKinect()
{
    mv_grabber->stop();
}
