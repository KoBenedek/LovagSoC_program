/**
 *  Copyright (C) 2022 Benedek Kocsis
 *
 *  File name:      DRV8305Registers.h
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *  
 *  Description:    Code containing the register definitions
 * 					for the DRV8305 FET driver IC.
 */

#ifndef DRV8305Registers_H_
#define DRV8305Registers_H_

#include "stdint.h"

/* following defines should be used for structure members */
#ifndef __IM
 #define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#endif

#ifndef __OM
 #define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#endif

#ifndef __IOM
 #define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */
#endif

typedef struct
{
	union
	{
		__IOM uint16_t reg;

		struct 
		{
			__IOM uint16_t OTW				: 1;
			__IOM uint16_t TEMP_FLAG3		: 1;
			__IOM uint16_t TEMP_FLAG2 		: 1;
			__IOM uint16_t TEMP_FLAG1		: 1;
			__IOM uint16_t VCHP_UVFL 		: 1;
			__IOM uint16_t VDS_STATUS 		: 1;
			__IOM uint16_t PVDD_OVFL		: 1;
			__IOM uint16_t PVDD_UVFL 		: 1;
			__IOM uint16_t TEMP_FLAG4 		: 1;
				  uint16_t					: 1;
			__IOM uint16_t FAULT 			: 1;
				  uint16_t 					: 5;
		} bit;
	} WNWR;
	
	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t SNS_A_OCP 		: 1;
			__IOM uint16_t SNS_B_OCP 		: 1;
			__IOM uint16_t SNS_C_OCP 		: 1;
				  uint16_t					: 2;
			__IOM uint16_t VDS_LC 			: 1;
			__IOM uint16_t VDS_HC 			: 1;
			__IOM uint16_t VDS_LB 			: 1;
			__IOM uint16_t VDS_HB 			: 1;
			__IOM uint16_t VDS_LA 			: 1;
			__IOM uint16_t VDS_HA 			: 1;
				  uint16_t					: 5;
		} bit;
	} VDSF;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t VCPH_OVLO_ABS	: 1;
			__IOM uint16_t VCPH_OVLO		: 1;
			__IOM uint16_t VCPH_UVLO2		: 1;
				  uint16_t					: 1;
			__IOM uint16_t VCP_LSD_UVLO2	: 1;
			__IOM uint16_t AVDD_UVLO		: 1;
			__IOM uint16_t VREG_UV			: 1;
				  uint16_t					: 1;
			__IOM uint16_t OTSD				: 1;
			__IOM uint16_t WD_FAULT			: 1;
			__IOM uint16_t PVDD_UVLO2		: 1;
				  uint16_t					: 5;
		} bit;
	} ICFR;

	union
	{
		__IOM uint16_t reg;

		struct
		{
				  uint16_t 					: 5;
			__IOM uint16_t VGS_LC			: 1;
			__IOM uint16_t VGS_HC			: 1;
			__IOM uint16_t VGS_LB			: 1;
			__IOM uint16_t VGS_HB			: 1;
			__IOM uint16_t VGS_LA			: 1;
			__IOM uint16_t VGS_HA			: 1;
				  uint16_t					: 5;
		} bit;
	} VGSF;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t IDRIVEP_HS		: 4;
			__IOM uint16_t IDRIVEN_HS		: 4;
			__IOM uint16_t TDRIVEN			: 2;
				  uint16_t					: 1;
				  uint16_t					: 5;
		} bit;
	} HGDC;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t IDRIVEP_HS		: 4;
			__IOM uint16_t IDRIVEN_HS		: 4;
			__IOM uint16_t TDRIVEN			: 2;
				  uint16_t					: 1;
				  uint16_t					: 5;
		} bit;
	} LGDC;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t TVDS				: 2;
			__IOM uint16_t TBLANK			: 2;
			__IOM uint16_t DEAD_TIME		: 3;
			__IOM uint16_t PWM_MODE			: 2;
			__IOM uint16_t COMM_OPTION		: 1;
				  uint16_t					: 5;
		} bit;
	} GDCR;

	union
	{
		struct
		{
				  uint16_t					: 16;
		};
	} ;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t SET_VCPH_UV		: 1;
			__IOM uint16_t CLR_FLTS			: 1;
			__IOM uint16_t SLEEP			: 1;
			__IOM uint16_t WD_EN			: 1;
			__IOM uint16_t DIS_SNS_OCP		: 1;
			__IOM uint16_t WD_DLY			: 2;
			__IOM uint16_t EN_SNS_CLAMP 	: 1;
			__IOM uint16_t DIS_GDRV_FAULT 	: 1;
			__IOM uint16_t DIS_PVDD_UVLO2 	: 1;
			__IOM uint16_t FLIP_OTSD	 	: 1;
				  uint16_t					: 5;
		} bit;
	} ICOR;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t GAIN_CS1		 	: 2;
			__IOM uint16_t GAIN_CS2		 	: 2;
			__IOM uint16_t GAIN_CS3		 	: 2;
			__IOM uint16_t CS_BLANK		 	: 2;
			__IOM uint16_t DC_CAL_CH1	 	: 1;
			__IOM uint16_t DC_CAL_CH2	 	: 1;
			__IOM uint16_t DC_CAL_CH3	 	: 1;
				  uint16_t					: 5;
		} bit;
	} SACR;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t VREG_UV_LEVEL 	: 2;
			__IOM uint16_t DIS_VREG_PWRGD 	: 1;
			__IOM uint16_t SLEEP_DLY 	 	: 2;
				  uint16_t					: 3;
			__IOM uint16_t VREF_SCALE 	 	: 2;
				  uint16_t					: 1;
				  uint16_t					: 5;
		} bit;
	} VRCR;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t VDS_MODE 	 	: 3;
			__IOM uint16_t VDS_LEVEL		: 5;
				  uint16_t					: 3;
				  uint16_t					: 5;
		} bit;
	} VDSS;
} DRV8305_Typedef;

/**
 * Warning and watchdog reset register definitions
 */
#define WNWR_OTW_Pos					(0u)
#define WNWR_OTW_Msk					(0x01u << WNWR_OTW_Pos)
#define WNWR_OTW						(WNWR_OTW_Msk)						/* Overtemperature warning */
#define WNWR_TEMP_FLAG3_Pos				(1u)
#define WNWR_TEMP_FLAG3_Msk				(0x01u << WNWR_TEMP_FLAG3_Pos)
#define WNWR_TEMP_FLAG3					(WNWR_TEMP_FLAG3_Msk)				/* Temperature flag setting for approximately 135°C */
#define WNWR_TEMP_FLAG2_Pos				(2u)
#define WNWR_TEMP_FLAG2_Msk				(0x01u << WNWR_TEMP_FLAG2_Pos)
#define WNWR_TEMP_FLAG2					(WNWR_TEMP_FLAG2_Msk)				/* Temperature flag setting for approximately 125°C */
#define WNWR_TEMP_FLAG1_Pos				(3u)
#define WNWR_TEMP_FLAG1_Msk				(0x01u << WNWR_TEMP_FLAG1_Pos)
#define WNWR_TEMP_FLAG1					(WNWR_TEMP_FLAG1_Msk)				/* Temperature flag setting for approximately 105°C */
#define WNWR_VCHP_UVFL_Pos				(4u)
#define WNWR_VCHP_UVFL_Msk				(0x01u << WNWR_VCHP_UVFL_Pos)
#define WNWR_VCHP_UVFL					(WNWR_VCHP_UVFL_Msk)				/* Charge pump undervoltage flag warning */
#define WNWR_VDS_STATUS_Pos				(5u)
#define WNWR_VDS_STATUS_Msk				(0x01u << WNWR_VDS_STATUS_Pos)
#define WNWR_VDS_STATUS					(WNWR_VDS_STATUS_Msk)				/* Real time OR of all VDS overcurrent monitors */
#define WNWR_PVDD_OVFL_Pos				(6u)
#define WNWR_PVDD_OVFL_Msk				(0x01u << WNWR_PVDD_OVFL_Pos)
#define WNWR_PVDD_OVFL					(WNWR_PVDD_OVFL_Msk)				/* PVDD overvoltage flag warning */
#define WNWR_PVDD_UVFL_Pos				(7u)
#define WNWR_PVDD_UVFL_Msk				(0x01u << WNWR_PVDD_UVFL_Pos)
#define WNWR_PVDD_UVFL					(WNWR_PVDD_UVFL_Msk)				/* PVDD undervoltage flag warning */
#define WNWR_TEMP_FLAG4_Pos				(8u)
#define WNWR_TEMP_FLAG4_Msk				(0x01u << WNWR_TEMP_FLAG4_Pos)
#define WNWR_TEMP_FLAG4					(WNWR_TEMP_FLAG4_Msk)				/* Temperature flag setting for approximately 175°C */
#define WNWR_FAULT_Pos					(10u)
#define WNWR_FAULT_Msk					(0x01u << WNWR_FAULT_Pos)
#define WNWR_FAULT						(WNWR_FAULT_Msk)					/* Fault indication */

/**
 * OV/VDS faults register definitions
 */
#define VDSF_SNS_A_OCP_Pos				(0u)
#define VDSF_SNS_A_OCP_Msk				(0x01u << VDSF_SNS_A_OCP_Pos)
#define VDSF_SNS_A_OCP					(VDSF_SNS_A_OCP_Msk)				/* Sense A overcurrent fault */
#define VDSF_SNS_B_OCP_Pos				(1u)
#define VDSF_SNS_B_OCP_Msk				(0x01u << VDSF_SNS_B_OCP_Pos)
#define VDSF_SNS_B_OCP					(VDSF_SNS_B_OCP_Msk)				/* Sense B overcurrent fault */
#define VDSF_SNS_C_OCP_Pos				(2u)
#define VDSF_SNS_C_OCP_Msk				(0x01u << VDSF_SNS_C_OCP_Pos)
#define VDSF_SNS_C_OCP					(VDSF_SNS_C_OCP_Msk)				/* Sense C overcurrent fault */
#define VDSF_VDS_LC_Pos					(5u)
#define VDSF_VDS_LC_Msk					(0x01u << VDSF_VDS_LC_Pos)
#define VDSF_VDS_LC						(VDSF_VDS_LC_Msk)					/* VDS overcurrent fault for low-side MOSFET C */
#define VDSF_VDS_HC_Pos					(6u)
#define VDSF_VDS_HC_Msk					(0x01u << VDSF_VDS_HC_Pos)
#define VDSF_VDS_HC						(VDSF_VDS_HC_Msk)					/* VDS overcurrent fault for high-side MOSFET C */
#define VDSF_VDS_LB_Pos					(7u)
#define VDSF_VDS_LB_Msk					(0x01u << VDSF_VDS_LB_Pos)
#define VDSF_VDS_LB						(VDSF_VDS_LB_Msk)					/* VDS overcurrent fault for low-side MOSFET B */
#define VDSF_VDS_HB_Pos					(8u)
#define VDSF_VDS_HB_Msk					(0x01u << VDSF_VDS_HB_Pos)
#define VDSF_VDS_HB						(VDSF_VDS_HB_Msk)					/* VDS overcurrent fault for high-side MOSFET B */
#define VDSF_VDS_LA_Pos					(9u)
#define VDSF_VDS_LA_Msk					(0x01u << VDSF_VDS_LA_Pos)
#define VDSF_VDS_LA						(VDSF_VDS_LA_Msk)					/* VDS overcurrent fault for low-side MOSFET A */
#define VDSF_VDS_HA_Pos					(10u)
#define VDSF_VDS_HA_Msk					(0x01u << VDSF_VDS_HA_Pos)
#define VDSF_VDS_HA						(VDSF_VDS_HA_Msk)					/* VDS overcurrent fault for high-side MOSFET A */

/**
 * IC faults register definitions
 */
#define ICFR_VCPH_OVLO_ABS_Pos			(0u)
#define ICFR_VCPH_OVLO_ABS_Msk			(0x01u << ICFR_VCPH_OVLO_ABS_Pos)
#define ICFR_VCPH_OVLO_ABS				(ICFR_VCPH_OVLO_ABS_Msk)			/* High-side charge pump overvoltage ABS fault */
#define ICFR_VCPH_OVLO_Pos				(1u)
#define ICFR_VCPH_OVLO_Msk				(0x01u << ICFR_VCPH_OVLO_Pos)
#define ICFR_VCPH_OVLO					(ICFR_VCPH_OVLO_Msk)				/* High-side charge pump overvoltage fault */
#define ICFR_VCPH_UVLO2_Pos				(2u)
#define ICFR_VCPH_UVLO2_Msk				(0x01u << ICFR_VCPH_UVLO2_Pos)
#define ICFR_VCPH_UVLO2					(ICFR_VCPH_UVLO2_Msk)				/* High-side charge pump undervoltage 2 fault */
#define ICFR_VCP_LSD_UVLO2_Pos			(4u)
#define ICFR_VCP_LSD_UVLO2_Msk			(0x01u << ICFR_VCP_LSD_UVLO2_Pos)
#define ICFR_VCP_LSD_UVLO2				(ICFR_VCP_LSD_UVLO2_Msk)			/* Low-side gate supply fault */
#define ICFR_AVDD_UVLO_Pos				(5u)
#define ICFR_AVDD_UVLO_Msk				(0x01u << ICFR_AVDD_UVLO_Pos)
#define ICFR_AVDD_UVLO					(ICFR_AVDD_UVLO_Msk)				/* AVDD undervoltage fault */
#define ICFR_VREG_UV_Pos				(6u)
#define ICFR_VREG_UV_Msk				(0x01u << ICFR_VREG_UV_Pos)
#define ICFR_VREG_UV					(ICFR_VREG_UV_Msk)					/* VREG undervoltage fault */
#define ICFR_OTSD_Pos					(8u)
#define ICFR_OTSD_Msk					(0x01u << ICFR_OTSD_Pos)
#define ICFR_OTSD						(ICFR_OTSD_Msk)						/* Overtemperature fault */
#define ICFR_WD_FAULT_Pos				(9u)
#define ICFR_WD_FAULT_Msk				(0x01u << ICFR_WD_FAULT_Pos)
#define ICFR_WD_FAULT					(ICFR_WD_FAULT_Msk)					/* Watchdog fault */
#define ICFR_PVDD_UVLO2_Pos				(10u)
#define ICFR_PVDD_UVLO2_Msk				(0x01u << ICFR_PVDD_UVLO2_Pos)
#define ICFR_PVDD_UVLO2					(ICFR_PVDD_UVLO2_Msk)				/* PVDD undervoltage 2 fault */

/**
 * Gate driver VGS faults register definitions
 */
#define VGSF_VGS_LC_Pos					(5u)
#define VGSF_VGS_LC_Msk					(0x01u << VGSF_VGS_LC_Pos)
#define VGSF_VGS_LC						(VGSF_VGS_LC_Msk)					/* VGS gate drive fault for low-side MOSFET C */
#define VGSF_VGS_HC_Pos					(5u)
#define VGSF_VGS_HC_Msk					(0x01u << VGSF_VGS_HC_Pos)
#define VGSF_VGS_HC						(VGSF_VGS_HC_Msk)					/* VGS gate drive fault for high-side MOSFET C */
#define VGSF_VGS_LB_Pos					(6u)
#define VGSF_VGS_LB_Msk					(0x01u << VGSF_VGS_LB_Pos)
#define VGSF_VGS_LB						(VGSF_VGS_LB_Msk)					/* VGS gate drive fault for low-side MOSFET B */
#define VGSF_VGS_HB_Pos					(8u)
#define VGSF_VGS_HB_Msk					(0x01u << VGSF_VGS_HB_Pos)
#define VGSF_VGS_HB						(VGSF_VGS_HB_Msk)					/* VGS gate drive fault for high-side MOSFET B */
#define VGSF_VGS_LA_Pos					(9u)
#define VGSF_VGS_LA_Msk					(0x01u << VGSF_VGS_LA_Pos)
#define VGSF_VGS_LA						(VGSF_VGS_LA_Msk)					/* VGS gate drive fault for low-side MOSFET A */
#define VGSF_VGS_HA_Pos					(10u)
#define VGSF_VGS_HA_Msk					(0x01u << VGSF_VGS_HA_Pos)
#define VGSF_VGS_HA						(VGSF_VGS_HA_Msk)					/* VGS gate drive fault for high-side MOSFET A */

/**
 * High side gate drive control register definitions
 */
#define HGDC_IDRIVEP_HS_Pos				(0u)
#define HGDC_IDRIVEP_HS_Msk				(0x0Fu << HGDC_IDRIVEP_HS_Pos)
#define HGDC_IDRIVEP_HS					(HGDC_IDRIVEP_HS_Msk)				/* High-side gate driver peak source current */
#define HGDC_IDRIVEN_HS_Pos				(4u)
#define HGDC_IDRIVEN_HS_Msk				(0x0Fu << HGDC_IDRIVEN_HS_Pos)
#define HGDC_IDRIVEN_HS					(HGDC_IDRIVEN_HS_Msk)				/* High-side gate driver peak sink current */
#define HGDC_TDRIVEN_Pos				(8u)
#define HGDC_TDRIVEN_Msk				(0x03u << HGDC_TDRIVEN_Pos)
#define HGDC_TDRIVEN					(HGDC_TDRIVEN_Msk)					/* High-side gate driver peak source time */

/**
 * Low side gate drive control register definitions
 */
#define LGDC_IDRIVEP_LS_Pos				(0u)
#define LGDC_IDRIVEP_LS_Msk				(0x0Fu << LGDC_IDRIVEP_LS_Pos)
#define LGDC_IDRIVEP_LS					(LGDC_IDRIVEP_LS_Msk)				/* Low-side gate driver peak source current */
#define LGDC_IDRIVEN_LS_Pos				(4u)
#define LGDC_IDRIVEN_LS_Msk				(0x0Fu << LGDC_IDRIVEN_LS_Pos)
#define LGDC_IDRIVEN_LS					(LGDC_IDRIVEN_LS_Msk)				/* Low-side gate driver peak sink current */
#define LGDC_TDRIVEP_Pos				(8u)
#define LGDC_TDRIVEP_Msk				(0x03u << LGDC_TDRIVEP_Pos)
#define LGDC_TDRIVEP					(LGDC_TDRIVEP_Msk)					/* Low-side gate driver peak source time */

/**
 * Gate drive control register definitions
 */
#define GDCR_TVDS_Pos					(0u)
#define GDCR_TVDS_Msk					(0x03u << GDCR_TVDS_Pos)
#define GDCR_TVDS						(GDCR_TVDS_Msk)						/* VDS sense deglitch */
#define GDCR_TBLANK_Pos					(2u)
#define GDCR_TBLANK_Msk					(0x03u << GDCR_TBLANK_Pos)
#define GDCR_TBLANK						(GDCR_TBLANK_Msk)					/* VDS sense blanking */
#define GDCR_DEAD_TIME_Pos				(4u)
#define GDCR_DEAD_TIME_Msk				(0x07u << GDCR_DEAD_TIME_Pos)
#define GDCR_DEAD_TIME					(GDCR_DEAD_TIME_Msk)				/* Dead time */
#define GDCR_PWM_MODE_Pos				(7u)
#define GDCR_PWM_MODE_Msk				(0x03u << GDCR_PWM_MODE_Pos)
#define GDCR_PWM_MODE					(GDCR_PWM_MODE_Msk)					/* PWM Mode */
#define GDCR_COMM_OPTION_Pos			(9u)
#define GDCR_COMM_OPTION_Msk			(0x01u << GDCR_COMM_OPTION_Pos)
#define GDCR_COMM_OPTION				(GDCR_COMM_OPTION_Msk)				/* Rectification control (PWM_MODE = 10 only) */

/**
 * IC operation register definitions
 */
#define ICOR_SET_VCPH_UV_Pos			(0u)
#define ICOR_SET_VCPH_UV_Msk			(0x01u << ICOR_SET_VCPH_UV_Pos)
#define ICOR_SET_VCPH_UV				(ICOR_SET_VCPH_UV_Msk)				/* Set charge pump undervoltage threshold level */
#define ICOR_CLR_FLTS_Pos				(1u)
#define ICOR_CLR_FLTS_Msk				(0x01u << ICOR_CLR_FLTS_Pos)
#define ICOR_CLR_FLTS					(ICOR_CLR_FLTS_Msk)					/* Clear faults */
#define ICOR_SLEEP_Pos					(2u)
#define ICOR_SLEEP_Msk					(0x01u << ICOR_SLEEP_Pos)
#define ICOR_SLEEP						(ICOR_SLEEP_Msk)					/* Put device into sleep mode */
#define ICOR_WD_EN_Pos					(3u)
#define ICOR_WD_EN_Msk					(0x01u << ICOR_WD_EN_Pos)
#define ICOR_WD_EN						(ICOR_WD_EN_Msk)					/* Watchdog enable */
#define ICOR_DIS_SNS_OCP_Pos			(4u)
#define ICOR_DIS_SNS_OCP_Msk			(0x01u << ICOR_DIS_SNS_OCP_Pos)
#define ICOR_DIS_SNS_OCP				(ICOR_DIS_SNS_OCP_Msk)				/* Disable SNS overcurrent protection fault and reporting */
#define ICOR_WD_DLY_Pos					(5u)
#define ICOR_WD_DLY_Msk					(0x03u << ICOR_WD_DLY_Pos)
#define ICOR_WD_DLY						(ICOR_WD_DLY_Msk)					/* Watchdog delay */
#define ICOR_EN_SNS_CLAMP_Pos			(7u)
#define ICOR_EN_SNS_CLAMP_Msk			(0x01u << ICOR_EN_SNS_CLAMP_Pos)
#define ICOR_EN_SNS_CLAMP				(ICOR_EN_SNS_CLAMP_Msk)				/* Enable sense amplifier clamp */
#define ICOR_DIS_GDRV_FAULT_Pos			(8u)
#define ICOR_DIS_GDRV_FAULT_Msk			(0x01u << ICOR_DIS_GDRV_FAULT_Pos)
#define ICOR_DIS_GDRV_FAULT				(ICOR_DIS_GDRV_FAULT_Msk)			/* Disable gate drive fault and reporting */
#define ICOR_DIS_PVDD_UVLO2_Pos			(9u)
#define ICOR_DIS_PVDD_UVLO2_Msk			(0x01u << ICOR_DIS_PVDD_UVLO2_Pos)
#define ICOR_DIS_PVDD_UVLO2				(ICOR_DIS_PVDD_UVLO2_Msk)			/* Disable PVDD_UVLO2 fault and reporting */
#define ICOR_FLIP_OTSD_Pos				(10u)
#define ICOR_FLIP_OTSD_Msk				(0x01u << ICOR_FLIP_OTSD_Pos)
#define ICOR_FLIP_OTSD					(ICOR_FLIP_OTSD_Msk)				/* Enable OTSD */

/**
 * Shunt amplifier control register definitions
 */
#define SACR_GAIN_CS1_Pos				(0u)
#define SACR_GAIN_CS1_Msk				(0x03u << SACR_GAIN_CS1_Pos)
#define SACR_GAIN_CS1					(SACR_GAIN_CS1_Msk)					/* Gain of CS amplifier 1 */
#define SACR_GAIN_CS2_Pos				(2u)
#define SACR_GAIN_CS2_Msk				(0x03u << SACR_GAIN_CS2_Pos)
#define SACR_GAIN_CS2					(SACR_GAIN_CS2_Msk)					/* Gain of CS amplifier 2 */
#define SACR_GAIN_CS3_Pos				(4u)
#define SACR_GAIN_CS3_Msk				(0x03u << SACR_GAIN_CS3_Pos)
#define SACR_GAIN_CS3					(SACR_GAIN_CS3_Msk)					/* Gain of CS amplifier 3 */
#define SACR_CS_BLANK_Pos				(6u)
#define SACR_CS_BLANK_Msk				(0x03u << SACR_CS_BLANK_Pos)
#define SACR_CS_BLANK					(SACR_CS_BLANK_Msk)					/* Current shunt amplifier blanking time */
#define SACR_DC_CAL_CH1_Pos				(8u)
#define SACR_DC_CAL_CH1_Msk				(0x01u << SACR_DC_CAL_CH1_Pos)
#define SACR_DC_CAL_CH1					(SACR_DC_CAL_CH1_Msk)				/* DC calibration of CS amplifier 1 */
#define SACR_DC_CAL_CH2_Pos				(9u)
#define SACR_DC_CAL_CH2_Msk				(0x01u << SACR_DC_CAL_CH2_Pos)
#define SACR_DC_CAL_CH2					(SACR_DC_CAL_CH2_Msk)				/* DC calibration of CS amplifier 2 */
#define SACR_DC_CAL_CH3_Pos				(10u)
#define SACR_DC_CAL_CH3_Msk				(0x01u << SACR_DC_CAL_CH3_Pos)
#define SACR_DC_CAL_CH3					(SACR_DC_CAL_CH3_Msk)				/* DC calibration of CS amplifier 3 */

/**
 * Voltage regulator control register definitions
 */
#define VRCR_VREG_UV_LEVEL_Pos			(0u)
#define VRCR_VREG_UV_LEVEL_Msk			(0x03u << VRCR_VREG_UV_LEVEL_Pos)
#define VRCR_VREG_UV_LEVEL				(VRCR_VREG_UV_LEVEL_Msk)			/* VREG undervoltage set point */
#define VRCR_DIS_VREG_PWRGD_Pos			(2u)
#define VRCR_DIS_VREG_PWRGD_Msk			(0x01u << VRCR_DIS_VREG_PWRGD_Pos)
#define VRCR_DIS_VREG_PWRGD				(VRCR_DIS_VREG_PWRGD_Msk)			/* Disable VREG undervoltage fault and reporting */
#define VRCR_SLEEP_DLY_Pos				(3u)
#define VRCR_SLEEP_DLY_Msk				(0x03u << VRCR_SLEEP_DLY_Pos)
#define VRCR_SLEEP_DLY					(VRCR_SLEEP_DLY_Msk)				/* Delay to power down VREG after SLEEP */
#define VRCR_VREF_SCALE_Pos				(8u)
#define VRCR_VREF_SCALE_Msk				(0x03u << VRCR_VREF_SCALE_Pos)
#define VRCR_VREF_SCALE					(VRCR_VREF_SCALE_Msk)				/* VREF Scaling */

/**
 * VDS sense control register definitions
 */
#define VDSS_VDS_MODE_Pos			(0u)
#define VDSS_VDS_MODE_Msk			(0x07u << VDSS_VDS_MODE_Pos)
#define VDSS_VDS_MODE				(VDSS_VDS_MODE_Msk)						/* VDS mode */
#define VDSS_VDS_LEVEL_Pos			(3u)
#define VDSS_VDS_LEVEL_Msk			(0x1Fu << VDSS_VDS_LEVEL_Pos)
#define VDSS_VDS_LEVEL				(VDSS_VDS_LEVEL_Msk)					/* VDS comparator threshold */

/**
 * DRV8305 register addresses
 */
typedef enum
{
	DRV8305_WNWR	= 0x1,			/* Warning and watchdog reset register */
	DRV8305_VDSF	= 0x2,			/* OV/VDS faults register  */
	DRV8305_ICFR	= 0x3,			/* IC faults register */
	DRV8305_VGSF	= 0x4,			/* Gate driver VGS faults register */
	DRV8305_HGDC	= 0x5,			/* High side gate drive control register */
	DRV8305_LGDC	= 0x6,			/* Low side gate drive control register */
	DRV8305_GDCR	= 0x7,			/* Gate drive control register */
	DRV8305_ICOR	= 0x9,			/* IC operation register */
	DRV8305_SACR	= 0xA,			/* Shunt amplifier control register */
	DRV8305_VRCR	= 0xB,			/* Voltage regulator control register */
	DRV8305_VDSS	= 0xC			/* VDS sense control register */
} DRV8305_Address_t;

#endif /* DRV8305Registers_H_ */
