#include "PACKAGES_CONFIG.h"

c     ==================================================================
c     HEADER COST
c     ==================================================================
c
c     o Header for model-data comparison.
c
c     The individual cost function contributions are multiplied by
c     factors mult_"var" which allow to switch off these contributions
c     without removing them in the adjoint code. This is useful for
c     doing tests with the adjoint and perhaps useful in assimilation
c     experiments where individual contributions are successively
c     switched on. For future applications it would be better to place
c     the initialisation of the multipliers somewhere else, for example
c     in a namelist, which is read in at the start of the model.
c
c     started: Christian Eckert eckert@mit.edu  24-Feb-1999
c     changed: Christian Eckert eckert@mit.edu
c     heimbach@mit.edu 05-Nov-2003 Modularize cost package
c
c     ==================================================================
c     HEADER COST
c     ==================================================================

c     The cost function, its contributions, and multipliers:
c     ======================================================
c
c     fc         - Final cost function.
c     glofc      - contributions from global mean constraints
c     mult_"var" - multipliers for the individual cost
c                  function contributions.

      common /cost_r/
     &                fc, glofc
      _RL  fc
      _RL  glofc

C     tile_fc   :: Final cost function contribution from this tile
      COMMON /COST_FINAL_R/ tile_fc
      _RL  tile_fc (nSx,nSy)

      common /cost_objf/
     &                objf_atl,
     &                objf_test,
     &                objf_tracer,
     &                objf_entropy,
     &                objf_t_misfit,
#ifdef ALLOW_COST_DEPTH
     &                objf_depth,
#endif
     &                objf_eflux
#ifdef ALLOW_COST_HFLUXM
     &               ,objf_hflux_tut
     &               ,objf_temp_tut
#endif

      _RL  objf_atl  (nSx,nSy)
      _RL  objf_test (nSx,nSy)
      _RL  objf_tracer (nSx,nSy)
      _RL  objf_entropy (nSx,nSy)
      _RL  objf_t_misfit (nSx,nSy)
      _RL  objf_eflux (nSx,nSy)
#ifdef ALLOW_COST_DEPTH
      _RL  objf_depth (nSx,nSy)
#endif
#ifdef ALLOW_COST_HFLUXM
      _RL  objf_hflux_tut (nSx,nSy)
      _RL  objf_temp_tut (nSx,nSy)
#endif

      common /cost_param_r/
     &                lastinterval
      _RL lastinterval

#ifdef ALLOW_COST_STATE_FINAL
      common /cost_state_final_r/
     &                objf_state_final
cph      _RL  objf_state_final (snx,sny,nsx,nsy)
      _RL  objf_state_final (sNx,sNy,nSx,nSy,4*Nr+1)
#endif

#ifdef ALLOW_COST_VECTOR
      common /cost_vector_r/
     &                objf_vector
      _RL  objf_vector (sNx,nSx,nSy)
#endif

      common /cost_fname_c/
     &     cost_mask_file
      CHARACTER*(MAX_LEN_FNAM) cost_mask_file

      common /cost_aux_r/
     &                    mult_atl,
     &                    mult_test,
     &                    mult_tracer,
     &                    mult_entropy,
     &                    mult_t_misfit,
     &                    mult_eflux,
     &                    multTheta,
     &                    multSalt,
     &                    multUvel,
     &                    multVvel,
#ifdef ALLOW_COST_DEPTH
     &           mult_depth,
#endif
     &                    multEtan
#ifdef ALLOW_COST_HFLUXM
     &                   ,mult_hflux_tut
     &                   ,mult_temp_tut
#endif

      _RL  mult_atl
      _RL  mult_test
      _RL  mult_tracer
      _RL  mult_entropy
      _RL  mult_t_misfit
      _RL  mult_eflux
      _RL  multTheta
      _RL  multSalt
      _RL  multUvel
      _RL  multVvel
      _RL  multEtan
#ifdef ALLOW_COST_DEPTH
      _RL  mult_depth
#endif
#ifdef ALLOW_COST_HFLUXM
      _RL  mult_hflux_tut
      _RL  mult_temp_tut
#endif

#ifdef ALLOW_COST_TEST
      common /cost_test_i/
     &                           iLocOut
     &                         , jLocOut
     &                         , kLocOut
      integer iLocOut
      integer jLocOut
      integer kLocOut
#endif

#ifdef ALLOW_COST
      COMMON /COST_MEAN_R/
     &                     cMeanTheta, cMeanUVel, cMeanVVel,
     &                     cMeanThetaUVel, cMeanThetaVVel
      _RL cMeanTheta(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL cMeanUVel(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL cMeanVVel(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL cMeanThetaUVel(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL cMeanThetaVVel(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
#endif

c     ==================================================================
c     END OF HEADER COST
c     ==================================================================
