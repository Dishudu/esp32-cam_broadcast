idf_component_register(
    SRCS 
        main.cpp
        wifi/wifi_setup.cpp
        camera/camera_task.cpp
        http/http_task.cpp

    INCLUDE_DIRS 
        .
        wifi
        camera
        http
)
