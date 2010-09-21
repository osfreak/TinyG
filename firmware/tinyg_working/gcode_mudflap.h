/*
data_gcode_contraptor_circles.h - data file containing gcode
*/

// mudflap test
const char PROGMEM mudflap[] = "\
G20	(inches mode)\n\
G40 G17\n\
T1 M06\n\
G90 G0 X0 Y0 Z0\n\
S5000 M03 \n\
G1 F30.0\n\
X0.076 Y0.341\n\
G1 Z-1.000 F90.0\n\
G1 Z-1.125 F30.0\n\
G1 F60.0\n\
X0.064 Y0.326\n\
X0.060 Y0.293\n\
X0.077 Y0.267\n\
X0.111 Y0.257\n\
X0.149 Y0.252\n\
X0.188 Y0.255\n\
X0.227 Y0.268\n\
X0.257 Y0.271\n\
X0.335 Y0.265\n\
X0.412 Y0.271\n\
X0.474 Y0.287\n\
X0.491 Y0.289\n\
X0.517 Y0.273\n\
X0.544 Y0.263\n\
X0.580 Y0.261\n\
X0.595 Y0.263\n\
X0.621 Y0.274\n\
X0.659 Y0.306\n\
X0.673 Y0.335\n\
X0.679 Y0.361\n\
X0.678 Y0.389\n\
X0.670 Y0.420\n\
X0.670 Y0.446\n\
X0.680 Y0.474\n\
X0.704 Y0.497\n\
X0.732 Y0.515\n\
X0.794 Y0.535\n\
X0.872 Y0.567\n\
X0.950 Y0.604\n\
X1.031 Y0.647\n\
X1.149 Y0.722\n\
X1.308 Y0.854\n\
X1.430 Y0.984\n\
X1.447 Y0.986\n\
X1.628 Y0.822\n\
X1.732 Y0.714\n\
X2.009 Y0.381\n\
X2.116 Y0.266\n\
X2.228 Y0.157\n\
X2.280 Y0.123\n\
X2.332 Y0.094\n\
X2.423 Y0.070\n\
X2.489 Y0.065\n\
X2.557 Y0.066\n\
X2.627 Y0.084\n\
X2.693 Y0.109\n\
X2.730 Y0.133\n\
X2.805 Y0.190\n\
X2.829 Y0.216\n\
X2.880 Y0.291\n\
X2.884 Y0.300\n\
X2.898 Y0.332\n\
X2.905 Y0.367\n\
X2.910 Y0.407\n\
X2.908 Y0.446\n\
X2.901 Y0.495\n\
X2.897 Y0.495\n\
X2.890 Y0.524\n\
X2.842 Y0.604\n\
X2.814 Y0.665\n\
X2.794 Y0.750\n\
X2.791 Y0.838\n\
X2.819 Y0.976\n\
X2.837 Y1.044\n\
X2.862 Y1.112\n\
X2.877 Y1.145\n\
X2.912 Y1.217\n\
X2.917 Y1.226\n\
X2.951 Y1.281\n\
X2.970 Y1.295\n\
X2.996 Y1.295\n\
X3.013 Y1.275\n\
X3.024 Y1.254\n\
X3.070 Y1.151\n\
X3.077 Y1.134\n\
X3.125 Y1.039\n\
X3.138 Y1.019\n\
X3.205 Y0.908\n\
X3.282 Y0.797\n\
X3.361 Y0.691\n\
X3.426 Y0.592\n\
X3.456 Y0.543\n\
X3.479 Y0.493\n\
X3.494 Y0.472\n\
X3.505 Y0.446\n\
X3.518 Y0.417\n\
X3.530 Y0.391\n\
X3.564 Y0.300\n\
X3.577 Y0.253\n\
X3.568 Y0.212\n\
X3.544 Y0.176\n\
X3.541 Y0.146\n\
X3.553 Y0.119\n\
X3.576 Y0.106\n\
X3.597 Y0.102\n\
X3.618 Y0.109\n\
X3.639 Y0.129\n\
X3.650 Y0.159\n\
X3.663 Y0.178\n\
X3.678 Y0.192\n\
X3.699 Y0.197\n\
X3.723 Y0.196\n\
X3.764 Y0.179\n\
X3.805 Y0.165\n\
X3.884 Y0.159\n\
X3.949 Y0.165\n\
X3.966 Y0.175\n\
X3.978 Y0.194\n\
X3.978 Y0.223\n\
X3.960 Y0.245\n\
X3.834 Y0.311\n\
X3.762 Y0.345\n\
X3.726 Y0.389\n\
X3.703 Y0.458\n\
X3.682 Y0.530\n\
X3.679 Y0.534\n\
X3.626 Y0.681\n\
X3.568 Y0.828\n\
X3.444 Y1.080\n\
X3.405 Y1.167\n\
X3.404 Y1.167\n\
X3.387 Y1.208\n\
X3.384 Y1.208\n\
X3.365 Y1.265\n\
X3.355 Y1.285\n\
X3.348 Y1.308\n\
X3.333 Y1.350\n\
X3.321 Y1.391\n\
X3.311 Y1.428\n\
X3.339 Y1.423\n\
X3.440 Y1.406\n\
X3.510 Y1.408\n\
X3.585 Y1.421\n\
X3.611 Y1.439\n\
X3.611 Y1.441\n\
X3.615 Y1.441\n\
X3.636 Y1.488\n\
X3.634 Y1.517\n\
X3.622 Y1.543\n\
X3.605 Y1.563\n\
X3.576 Y1.575\n\
X3.544 Y1.581\n\
X3.479 Y1.592\n\
X3.451 Y1.598\n\
X3.387 Y1.626\n\
X3.390 Y1.636\n\
X3.532 Y1.602\n\
X3.601 Y1.597\n\
X3.668 Y1.598\n\
X3.782 Y1.612\n\
X3.794 Y1.618\n\
X3.868 Y1.636\n\
X3.918 Y1.655\n\
X3.945 Y1.667\n\
X3.964 Y1.685\n\
X3.967 Y1.685\n\
X3.974 Y1.699\n\
X3.984 Y1.725\n\
X3.984 Y1.758\n\
X3.970 Y1.790\n\
X3.945 Y1.817\n\
X3.918 Y1.826\n\
X3.891 Y1.827\n\
X3.842 Y1.809\n\
X3.798 Y1.784\n\
X3.746 Y1.772\n\
X3.698 Y1.764\n\
X3.635 Y1.766\n\
X3.553 Y1.785\n\
X3.478 Y1.820\n\
X3.409 Y1.864\n\
X3.345 Y1.918\n\
X3.264 Y2.023\n\
X3.248 Y2.051\n\
X3.240 Y2.081\n\
X3.316 Y2.086\n\
X3.390 Y2.104\n\
X3.414 Y2.121\n\
X3.431 Y2.153\n\
X3.433 Y2.180\n\
X3.427 Y2.205\n\
X3.413 Y2.224\n\
X3.392 Y2.242\n\
X3.335 Y2.244\n\
X3.278 Y2.236\n\
X3.256 Y2.242\n\
X3.239 Y2.251\n\
X3.211 Y2.280\n\
X3.174 Y2.356\n\
X3.159 Y2.397\n\
X3.150 Y2.438\n\
X3.140 Y2.481\n\
X3.132 Y2.510\n\
X3.118 Y2.543\n\
X3.099 Y2.576\n\
X3.051 Y2.631\n\
X3.003 Y2.666\n\
X2.957 Y2.685\n\
X2.907 Y2.699\n\
X2.860 Y2.711\n\
X2.819 Y2.727\n\
X2.768 Y2.745\n\
X2.716 Y2.757\n\
X2.675 Y2.757\n\
X2.579 Y2.731\n\
X2.570 Y2.723\n\
X2.559 Y2.720\n\
X2.530 Y2.701\n\
X2.501 Y2.693\n\
X2.471 Y2.683\n\
X2.443 Y2.668\n\
X2.396 Y2.634\n\
X2.354 Y2.591\n\
X2.352 Y2.591\n\
X2.325 Y2.543\n\
X2.315 Y2.521\n\
X2.307 Y2.498\n\
X2.296 Y2.464\n\
X2.293 Y2.427\n\
X2.295 Y2.366\n\
X2.321 Y2.303\n\
X2.358 Y2.247\n\
X2.419 Y2.203\n\
X2.419 Y2.179\n\
X2.405 Y2.158\n\
X2.362 Y2.123\n\
X2.354 Y2.104\n\
X2.354 Y2.091\n\
X2.380 Y2.065\n\
X2.410 Y2.051\n\
X2.410 Y2.047\n\
X2.405 Y2.028\n\
X2.408 Y2.010\n\
X2.416 Y1.995\n\
X2.433 Y1.982\n\
X2.438 Y1.963\n\
X2.447 Y1.948\n\
X2.461 Y1.938\n\
X2.480 Y1.931\n\
X2.478 Y1.899\n\
X2.487 Y1.875\n\
X2.504 Y1.854\n\
X2.527 Y1.848\n\
X2.549 Y1.849\n\
X2.577 Y1.861\n\
X2.604 Y1.866\n\
X2.631 Y1.854\n\
X2.640 Y1.827\n\
X2.640 Y1.792\n\
X2.629 Y1.759\n\
X2.612 Y1.727\n\
X2.576 Y1.694\n\
X2.536 Y1.662\n\
X2.470 Y1.616\n\
X2.345 Y1.551\n\
X2.307 Y1.521\n\
X2.260 Y1.482\n\
X2.243 Y1.477\n\
X2.228 Y1.469\n\
X2.222 Y1.448\n\
X2.228 Y1.425\n\
X2.254 Y1.405\n\
X2.268 Y1.373\n\
X2.279 Y1.342\n\
X2.308 Y1.287\n\
X2.340 Y1.254\n\
X2.407 Y1.201\n\
X2.441 Y1.156\n\
X2.454 Y1.131\n\
X2.460 Y1.106\n\
X2.464 Y1.102\n\
X2.471 Y1.036\n\
X2.466 Y0.971\n\
X2.451 Y0.897\n\
X2.415 Y0.791\n\
X2.403 Y0.767\n\
X2.388 Y0.765\n\
X2.306 Y0.841\n\
X2.222 Y0.911\n\
X2.114 Y0.995\n\
X2.002 Y1.076\n\
X1.905 Y1.139\n\
X1.754 Y1.223\n\
X1.637 Y1.278\n\
X1.582 Y1.301\n\
X1.558 Y1.315\n\
X1.460 Y1.352\n\
X1.399 Y1.360\n\
X1.338 Y1.354\n\
X1.287 Y1.329\n\
X1.248 Y1.294\n\
X1.217 Y1.254\n\
X1.214 Y1.252\n\
X1.172 Y1.195\n\
X1.128 Y1.139\n\
X1.110 Y1.117\n\
X0.958 Y0.941\n\
X0.891 Y0.873\n\
X0.825 Y0.808\n\
X0.755 Y0.747\n\
X0.619 Y0.633\n\
X0.477 Y0.526\n\
X0.477 Y0.524\n\
X0.411 Y0.476\n\
X0.331 Y0.454\n\
X0.278 Y0.427\n\
X0.231 Y0.397\n\
X0.183 Y0.379\n\
X0.135 Y0.365\n\
X0.076 Y0.341\n\
G1 Z-0.875 F90.0\n\
G1 F30.0\n\
M05\n\
G21\n\
G90 X0 Y0 Z0 M30";
