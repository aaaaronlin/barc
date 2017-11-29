// Generated by gencpp from file data_service/TimeSeries.msg
// DO NOT EDIT!


#ifndef DATA_SERVICE_MESSAGE_TIMESERIES_H
#define DATA_SERVICE_MESSAGE_TIMESERIES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <data_service/TimeData.h>

namespace data_service
{
template <class ContainerAllocator>
struct TimeSeries_
{
  typedef TimeSeries_<ContainerAllocator> Type;

  TimeSeries_()
    : series()  {
    }
  TimeSeries_(const ContainerAllocator& _alloc)
    : series(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::data_service::TimeData_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::data_service::TimeData_<ContainerAllocator> >::other >  _series_type;
  _series_type series;




  typedef boost::shared_ptr< ::data_service::TimeSeries_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::data_service::TimeSeries_<ContainerAllocator> const> ConstPtr;

}; // struct TimeSeries_

typedef ::data_service::TimeSeries_<std::allocator<void> > TimeSeries;

typedef boost::shared_ptr< ::data_service::TimeSeries > TimeSeriesPtr;
typedef boost::shared_ptr< ::data_service::TimeSeries const> TimeSeriesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::data_service::TimeSeries_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::data_service::TimeSeries_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace data_service

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'data_service': ['/home/odroid/barc/workspace/src/data_service/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::data_service::TimeSeries_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::data_service::TimeSeries_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::data_service::TimeSeries_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::data_service::TimeSeries_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::data_service::TimeSeries_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::data_service::TimeSeries_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::data_service::TimeSeries_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ecf556e37ef3615e6c95590390588636";
  }

  static const char* value(const ::data_service::TimeSeries_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xecf556e37ef3615eULL;
  static const uint64_t static_value2 = 0x6c95590390588636ULL;
};

template<class ContainerAllocator>
struct DataType< ::data_service::TimeSeries_<ContainerAllocator> >
{
  static const char* value()
  {
    return "data_service/TimeSeries";
  }

  static const char* value(const ::data_service::TimeSeries_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::data_service::TimeSeries_<ContainerAllocator> >
{
  static const char* value()
  {
    return "TimeData[] series\n\
\n\
================================================================================\n\
MSG: data_service/TimeData\n\
float64 timestamp\n\
float64[] value\n\
";
  }

  static const char* value(const ::data_service::TimeSeries_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::data_service::TimeSeries_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.series);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TimeSeries_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::data_service::TimeSeries_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::data_service::TimeSeries_<ContainerAllocator>& v)
  {
    s << indent << "series[]" << std::endl;
    for (size_t i = 0; i < v.series.size(); ++i)
    {
      s << indent << "  series[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::data_service::TimeData_<ContainerAllocator> >::stream(s, indent + "    ", v.series[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DATA_SERVICE_MESSAGE_TIMESERIES_H
