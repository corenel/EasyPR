%module plate_detector

%include <opencv.i>
%cv_instantiate_all_defaults

%{
    #include "wrapper.h"
%}

%include "wrapper.h"
