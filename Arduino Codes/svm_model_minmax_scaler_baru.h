#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DeadliftSVM {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        float kernels[88] = { 0 };
                        float decisions[3] = { 0 };
                        int votes[3] = { 0 };
                        kernels[0] = compute_kernel(x,   0.739068100358  , 0.307242136064  , 0.727954971857  , 0.671000565291  , 0.251182343668  , 0.366689053056 );
                        kernels[1] = compute_kernel(x,   0.833691756272  , 0.313094367228  , 0.267041901188  , 0.733747880158  , 0.817130846033  , 0.571524513096 );
                        kernels[2] = compute_kernel(x,   0.813620071685  , 0.323335771763  , 0.257661038149  , 0.72244205766  , 0.763005780347  , 0.574210879785 );
                        kernels[3] = compute_kernel(x,   0.832974910394  , 0.321872713972  , 0.257661038149  , 0.730921424534  , 0.740935365213  , 0.584284754869 );
                        kernels[4] = compute_kernel(x,   0.85376344086  , 0.316752011704  , 0.259537210757  , 0.732052006783  , 0.769837099317  , 0.586971121558 );
                        kernels[5] = compute_kernel(x,   0.421505376344  , 0.319678127286  , 0.846153846154  , 0.509327303561  , 0.368891224383  , 0.527199462727 );
                        kernels[6] = compute_kernel(x,   0.432258064516  , 0.328456474031  , 0.815509693558  , 0.509327303561  , 0.368365738308  , 0.556077904634 );
                        kernels[7] = compute_kernel(x,   0.562724014337  , 0.414776883687  , 0.894308943089  , 0.543810062182  , 0.323173935891  , 0.49563465413 );
                        kernels[8] = compute_kernel(x,   0.83082437276  , 0.332114118508  , 0.253283302064  , 0.748445449406  , 0.814503415659  , 0.558764271323 );
                        kernels[9] = compute_kernel(x,   0.49247311828  , 0.376737381127  , 0.811757348343  , 0.507631430187  , 0.370993168681  , 0.51040967092 );
                        kernels[10] = compute_kernel(x,   0.81146953405  , 0.333577176298  , 0.253908692933  , 0.725833804409  , 0.769837099317  , 0.584284754869 );
                        kernels[11] = compute_kernel(x,   0.473835125448  , 0.359180687637  , 0.817385866166  , 0.524024872809  , 0.372569626905  , 0.490261920752 );
                        kernels[12] = compute_kernel(x,   0.394265232975  , 0.314557425018  , 0.865540963102  , 0.507066139062  , 0.345769837099  , 0.529885829416 );
                        kernels[13] = compute_kernel(x,   0.83082437276  , 0.325530358449  , 0.257661038149  , 0.738835500283  , 0.780872306884  , 0.558764271323 );
                        kernels[14] = compute_kernel(x,   0.643010752688  , 0.378931967813  , 0.677298311445  , 0.374788015828  , 0.487651077246  , 0.390194761585 );
                        kernels[15] = compute_kernel(x,   0.832974910394  , 0.337234820775  , 0.258286429018  , 0.729790842284  , 0.762480294272  , 0.558764271323 );
                        kernels[16] = compute_kernel(x,   0.74982078853  , 0.331382589612  , 0.578486554096  , 0.444318824194  , 0.327377824488  , 0.794492948287 );
                        kernels[17] = compute_kernel(x,   0.817921146953  , 0.324798829554  , 0.263289555972  , 0.745618993782  , 0.759852863899  , 0.583613163197 );
                        kernels[18] = compute_kernel(x,   0.468817204301  , 0.407461594733  , 0.818636647905  , 0.499152063313  , 0.371518654756  , 0.466084620551 );
                        kernels[19] = compute_kernel(x,   0.405734767025  , 0.333577176298  , 0.835522201376  , 0.508762012436  , 0.348397267472  , 0.521826729349 );
                        kernels[20] = compute_kernel(x,   0.479569892473  , 0.392831016825  , 0.838023764853  , 0.504804974562  , 0.377299001576  , 0.486232370719 );
                        kernels[21] = compute_kernel(x,   0.475268817204  , 0.384784198976  , 0.820512820513  , 0.495195025438  , 0.37992643195  , 0.487575554063 );
                        kernels[22] = compute_kernel(x,   0.374910394265  , 0.373811265545  , 0.838649155722  , 0.552289429056  , 0.353652128219  , 0.594358629953 );
                        kernels[23] = compute_kernel(x,   0.445878136201  , 0.17776152158  , 0.585991244528  , 0.507066139062  , 0.099842354178  , 0.515782404298 );
                        kernels[24] = compute_kernel(x,   0.83082437276  , 0.324067300658  , 0.27454659162  , 0.729225551159  , 0.774566473988  , 0.585627938214 );
                        kernels[25] = compute_kernel(x,   0.825089605735  , 0.331382589612  , 0.262038774234  , 0.734313171283  , 0.771413557541  , 0.568838146407 );
                        kernels[26] = compute_kernel(x,   0.416487455197  , 0.325530358449  , 0.85866166354  , 0.511023176936  , 0.37204414083  , 0.568838146407 );
                        kernels[27] = compute_kernel(x,   0.430107526882  , 0.343087051939  , 0.8492808005  , 0.492368569813  , 0.383079348397  , 0.520483546004 );
                        kernels[28] = compute_kernel(x,   0.358422939068  , 0.467446964155  , 0.906816760475  , 0.508196721311  , 0.311613242249  , 0.568838146407 );
                        kernels[29] = compute_kernel(x,   0.437275985663  , 0.334308705194  , 0.730456535335  , 0.087054833239  , 1.0  , 0.323035594359 );
                        kernels[30] = compute_kernel(x,   0.330465949821  , 0.37454279444  , 0.876797998749  , 0.504239683437  , 0.352601156069  , 0.409670920081 );
                        kernels[31] = compute_kernel(x,   0.488888888889  , 0.361375274323  , 0.799874921826  , 0.55850763143  , 0.431949553337  , 0.592343854936 );
                        kernels[32] = compute_kernel(x,   0.48458781362  , 0.430870519386  , 0.770481550969  , 0.574901074053  , 0.35838150289  , 0.574882471457 );
                        kernels[33] = compute_kernel(x,   0.4  , 0.304316020483  , 0.847404627892  , 0.484454494064  , 0.390961639517  , 0.378777703156 );
                        kernels[34] = compute_kernel(x,   0.480286738351  , 0.387710314557  , 0.815509693558  , 0.521198417185  , 0.408828166054  , 0.583613163197 );
                        kernels[35] = compute_kernel(x,   0.479569892473  , 0.384784198976  , 0.836147592245  , 0.539287733183  , 0.385181292696  , 0.57555406313 );
                        kernels[36] = compute_kernel(x,   0.443010752688  , 0.275786393563  , 0.844903064415  , 0.51950254381  , 0.40725170783  , 0.321692411014 );
                        kernels[37] = compute_kernel(x,   0.257347670251  , 0.313825896123  , 0.892432770482  , 0.472583380441  , 0.358906988965  , 0.592343854936 );
                        kernels[38] = compute_kernel(x,   0.397849462366  , 0.292611558157  , 0.861163227017  , 0.485019785189  , 0.389385181293  , 0.34116856951 );
                        kernels[39] = compute_kernel(x,   0.420071684588  , 0.278712509144  , 0.83176985616  , 0.511023176936  , 0.38570677877  , 0.33243787777 );
                        kernels[40] = compute_kernel(x,   0.495340501792  , 0.424286759327  , 0.806128830519  , 0.536461277558  , 0.406726221755  , 0.578240429819 );
                        kernels[41] = compute_kernel(x,   0.463082437276  , 0.395025603511  , 0.819262038774  , 0.561334087055  , 0.367840252233  , 0.605775688381 );
                        kernels[42] = compute_kernel(x,   0.437275985663  , 0.272860277981  , 0.828017510944  , 0.499717354438  , 0.403047819233  , 0.30557421088 );
                        kernels[43] = compute_kernel(x,   0.462365591398  , 0.373811265545  , 0.841776110069  , 0.617297908423  , 0.423016290068  , 0.57555406313 );
                        kernels[44] = compute_kernel(x,   0.370609318996  , 0.316752011704  , 0.87617260788  , 0.659129451668  , 0.49605885444  , 0.43922095366 );
                        kernels[45] = compute_kernel(x,   0.314695340502  , 0.264081931236  , 0.874921826141  , 0.613906161673  , 0.498160798739  , 0.363331094694 );
                        kernels[46] = compute_kernel(x,   0.476702508961  , 0.367227505486  , 0.82301438399  , 0.577727529678  , 0.421439831844  , 0.607790463398 );
                        kernels[47] = compute_kernel(x,   0.227956989247  , 0.21433796635  , 0.887429643527  , 0.715658564161  , 0.646347871781  , 0.487575554063 );
                        kernels[48] = compute_kernel(x,   0.469534050179  , 0.397951719093  , 0.803627267042  , 0.527981910684  , 0.398843930636  , 0.563465413029 );
                        kernels[49] = compute_kernel(x,   0.478136200717  , 0.370885149963  , 0.852407754847  , 0.639344262295  , 0.438780872307  , 0.565480188046 );
                        kernels[50] = compute_kernel(x,   0.481003584229  , 0.381126554499  , 0.816760475297  , 0.564160542679  , 0.361008933263  , 0.56682337139 );
                        kernels[51] = compute_kernel(x,   0.374910394265  , 0.325530358449  , 0.863039399625  , 0.585641605427  , 0.435627955859  , 0.691067830759 );
                        kernels[52] = compute_kernel(x,   0.387096774194  , 0.29041697147  , 0.86741713571  , 0.492368569813  , 0.37992643195  , 0.337810611148 );
                        kernels[53] = compute_kernel(x,   0.491756272401  , 0.377468910022  , 0.851156973108  , 0.550028264556  , 0.388859695218  , 0.595701813298 );
                        kernels[54] = compute_kernel(x,   0.412903225806  , 0.276517922458  , 0.854283927455  , 0.512719050311  , 0.416184971098  , 0.338482202821 );
                        kernels[55] = compute_kernel(x,   0.85017921147  , 0.373811265545  , 0.27392120075  , 0.768230638779  , 0.810825013137  , 0.594358629953 );
                        kernels[56] = compute_kernel(x,   0.412903225806  , 0.292611558157  , 0.828017510944  , 0.595816845676  , 0.447188649501  , 0.458025520484 );
                        kernels[57] = compute_kernel(x,   0.827240143369  , 0.3174835406  , 0.280800500313  , 0.733182589033  , 0.785076195481  , 0.509066487576 );
                        kernels[58] = compute_kernel(x,   0.848028673835  , 0.264813460132  , 0.251407129456  , 0.725268513284  , 0.734104046243  , 0.586971121558 );
                        kernels[59] = compute_kernel(x,   0.480286738351  , 0.286759326993  , 0.936210131332  , 0.644431882419  , 0.408828166054  , 0.46877098724 );
                        kernels[60] = compute_kernel(x,   0.669534050179  , 0.517190929042  , 0.581613508443  , 0.616732617298  , 0.546505517604  , 0.47481531229 );
                        kernels[61] = compute_kernel(x,   0.703225806452  , 0.232626188734  , 0.517198248906  , 0.599208592425  , 0.299527062533  , 0.532572196105 );
                        kernels[62] = compute_kernel(x,   0.799283154122  , 0.36356986101  , 0.361475922452  , 0.666478236292  , 0.722543352601  , 0.848891873741 );
                        kernels[63] = compute_kernel(x,   0.41146953405  , 0.284564740307  , 0.839899937461  , 0.572639909553  , 0.414608512874  , 0.503693754197 );
                        kernels[64] = compute_kernel(x,   0.403584229391  , 0.288222384784  , 0.842401500938  , 0.576596947428  , 0.412506568576  , 0.505036937542 );
                        kernels[65] = compute_kernel(x,   0.404301075269  , 0.28090709583  , 0.852407754847  , 0.583380440927  , 0.423541776143  , 0.488918737408 );
                        kernels[66] = compute_kernel(x,   0.414336917563  , 0.281638624726  , 0.883051907442  , 0.582249858677  , 0.409353652128  , 0.488918737408 );
                        kernels[67] = compute_kernel(x,   0.879569892473  , 0.221653255304  , 0.571607254534  , 0.475975127191  , 0.351024697846  , 0.437206178643 );
                        kernels[68] = compute_kernel(x,   0.820788530466  , 0.308705193855  , 0.345841150719  , 0.729790842284  , 0.859695218077  , 0.638683680322 );
                        kernels[69] = compute_kernel(x,   0.830107526882  , 0.367227505486  , 0.142589118199  , 0.704352741662  , 0.826064109301  , 0.58764271323 );
                        kernels[70] = compute_kernel(x,   0.818637992832  , 0.380395025604  , 0.207629768605  , 0.727529677784  , 0.796636889122  , 0.597716588314 );
                        kernels[71] = compute_kernel(x,   0.837275985663  , 0.343818580834  , 0.320825515947  , 0.771057094404  , 0.80662112454  , 0.588314304903 );
                        kernels[72] = compute_kernel(x,   0.405017921147  , 0.292611558157  , 0.847404627892  , 0.578858111928  , 0.421439831844  , 0.484889187374 );
                        kernels[73] = compute_kernel(x,   0.745519713262  , 0.356986100951  , 0.144465290807  , 0.693046919163  , 0.784550709406  , 0.660174613835 );
                        kernels[74] = compute_kernel(x,   0.906093189964  , 0.267739575713  , 0.575984990619  , 0.224420576597  , 0.458749343142  , 0.209536601746 );
                        kernels[75] = compute_kernel(x,   0.855197132616  , 0.320409656181  , 0.293308317699  , 0.747880158282  , 0.774040987914  , 0.593015446608 );
                        kernels[76] = compute_kernel(x,   0.893906810036  , 0.332845647403  , 0.329580988118  , 0.789711701526  , 0.803993694167  , 0.460711887173 );
                        kernels[77] = compute_kernel(x,   0.853046594982  , 0.333577176298  , 0.282051282051  , 0.737704918033  , 0.746715712034  , 0.627266621894 );
                        kernels[78] = compute_kernel(x,   0.868817204301  , 0.267008046818  , 0.217010631645  , 0.751271905031  , 0.777193904362  , 0.595701813298 );
                        kernels[79] = compute_kernel(x,   0.812186379928  , 0.299195318215  , 0.245778611632  , 0.72244205766  , 0.801891749869  , 0.513096037609 );
                        kernels[80] = compute_kernel(x,   0.615770609319  , 1.0  , 0.320825515947  , 0.752967778406  , 0.785601681555  , 0.551376762928 );
                        kernels[81] = compute_kernel(x,   0.812186379928  , 0.338697878566  , 0.280800500313  , 0.736574335783  , 0.798738833421  , 0.527199462727 );
                        kernels[82] = compute_kernel(x,   0.815053763441  , 0.373811265545  , 0.512820512821  , 0.651780667044  , 0.250656857593  , 0.541974479516 );
                        kernels[83] = compute_kernel(x,   0.403584229391  , 0.28090709583  , 0.843652282677  , 0.568117580554  , 0.412506568576  , 0.496306245803 );
                        kernels[84] = compute_kernel(x,   0.444444444444  , 0.27944403804  , 0.848030018762  , 0.582815149802  , 0.445086705202  , 0.454667562122 );
                        kernels[85] = compute_kernel(x,   0.405734767025  , 0.292611558157  , 0.842401500938  , 0.576596947428  , 0.416710457173  , 0.487575554063 );
                        kernels[86] = compute_kernel(x,   0.413620071685  , 0.284564740307  , 0.863664790494  , 0.578292820803  , 0.413032054651  , 0.481531229013 );
                        kernels[87] = compute_kernel(x,   0.837275985663  , 0.310168251646  , 0.305190744215  , 0.733747880158  , 0.781397792958  , 0.539288112827 );
                        decisions[0] = -0.330884422606
                        + kernels[5] * 100.0
                        + kernels[6] * 100.0
                        + kernels[7] * 7.213601093372
                        + kernels[9] * 33.264374039549
                        + kernels[11] * 100.0
                        + kernels[12] * 17.080452223016
                        + kernels[17] * 22.278255804965
                        + kernels[18] * 100.0
                        + kernels[19] * 100.0
                        + kernels[20] * 100.0
                        + kernels[21] * 100.0
                        + kernels[22] * 100.0
                        + kernels[26] * 100.0
                        + kernels[27] * 100.0
                        + kernels[28] * 97.904547644469
                        + kernels[29] * 6.906444207635
                        + kernels[30] * -100.0
                        + kernels[32] * -68.59714226234
                        + kernels[33] * -100.0
                        + kernels[34] * -100.0
                        + kernels[35] * -100.0
                        + kernels[37] * -100.0
                        + kernels[38] * -100.0
                        + kernels[40] * -82.620051308153
                        + kernels[41] * -100.0
                        + kernels[48] * -100.0
                        + kernels[50] * -100.0
                        + kernels[52] * -33.430481442514
                        + kernels[53] * -100.0
                        ;
                        decisions[1] = -2.64154470225
                        + kernels[0] * 100.0
                        + kernels[1] * 100.0
                        + kernels[2] * 100.0
                        + kernels[3] * 100.0
                        + kernels[4] * 100.0
                        + kernels[5] * 100.0
                        + kernels[8] * 100.0
                        + kernels[10] * 100.0
                        + kernels[13] * 100.0
                        + kernels[14] * 34.290703842152
                        + kernels[15] * 100.0
                        + kernels[16] * 21.778892106211
                        + kernels[17] * 100.0
                        + kernels[22] * 71.166607084978
                        + kernels[23] * 12.679413588176
                        + kernels[24] * 100.0
                        + kernels[25] * 100.0
                        + kernels[29] * 10.490254665067
                        + kernels[55] * -100.0
                        + kernels[57] * -100.0
                        + kernels[58] * -100.0
                        + kernels[60] * -56.013866292897
                        + kernels[61] * -38.027288319424
                        + kernels[62] * -12.260033186159
                        + kernels[63] * -100.0
                        + kernels[64] * -5.773930643829
                        + kernels[67] * -17.661258866261
                        + kernels[68] * -45.689662708739
                        + kernels[69] * -78.830640518432
                        + kernels[70] * -100.0
                        + kernels[71] * -18.846708533226
                        + kernels[73] * -42.821304812284
                        + kernels[74] * -14.544680393063
                        + kernels[75] * -100.0
                        + kernels[76] * -7.501576625343
                        + kernels[77] * -20.972443651781
                        + kernels[78] * -100.0
                        + kernels[79] * -100.0
                        + kernels[81] * -66.393204754448
                        + kernels[82] * -73.238522358356
                        + kernels[83] * -100.0
                        + kernels[87] * -51.83074962234
                        ;
                        decisions[2] = 5.091563795028
                        + kernels[31] * 100.0
                        + kernels[36] * 100.0
                        + kernels[39] * 100.0
                        + kernels[42] * 36.340333168537
                        + kernels[43] * 7.023737699427
                        + kernels[44] * 100.0
                        + kernels[45] * 4.251629250819
                        + kernels[46] * 100.0
                        + kernels[47] * 53.907449675636
                        + kernels[49] * 100.0
                        + kernels[50] * 62.288779730586
                        + kernels[51] * 38.248991608733
                        + kernels[54] * 69.029059100929
                        + kernels[56] * -100.0
                        + kernels[59] * -26.656827181139
                        + kernels[60] * -53.073748733093
                        + kernels[64] * -100.0
                        + kernels[65] * -70.763901326925
                        + kernels[66] * -100.0
                        + kernels[72] * -100.0
                        + kernels[74] * -11.905630048507
                        + kernels[80] * -8.689872945003
                        + kernels[84] * -100.0
                        + kernels[85] * -100.0
                        + kernels[86] * -100.0
                        ;
                        votes[decisions[0] > 0 ? 0 : 1] += 1;
                        votes[decisions[1] > 0 ? 0 : 2] += 1;
                        votes[decisions[2] > 0 ? 1 : 2] += 1;
                        int val = votes[0];
                        int idx = 0;

                        for (int i = 1; i < 3; i++) {
                            if (votes[i] > val) {
                                val = votes[i];
                                idx = i;
                            }
                        }

                        return idx;
                    }

                protected:
                    /**
                    * Compute kernel between feature vector and support vector.
                    * Kernel type: rbf
                    */
                    float compute_kernel(float *x, ...) {
                        va_list w;
                        va_start(w, 6);
                        float kernel = 0.0;

                        for (uint16_t i = 0; i < 6; i++) {
                            kernel += pow(x[i] - va_arg(w, double), 2);
                        }

                        return exp(-1.0 * kernel);
                    }
                };
            }
        }
    }