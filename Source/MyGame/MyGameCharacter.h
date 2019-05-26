// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyGameCharacter.generated.h"

UCLASS(config=Game)
class AMyGameCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/**Creacion del componente linterna */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Componetes, meta = (AllowPrivateAccess = "true"))
	class USpotLightComponent* Linterna;

	/*Creacion de la variable valor de salud*/
	UPROPERTY(EditAnyWhere,BlueprintReadWrite,Category ="Inventario", meta = (AllowPrivateAccess = "true"))
		float ValorDeSalud =0.75;

	/*Creacion de la variable valor de energia*/
	UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Inventario", meta = (AllowPrivateAccess = "true"))
		float ValorDeEnergia =0.5;

	/*Creacion de la variable valor de mood*/
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventario", meta = (AllowPrivateAccess = "true"))
		float ValorDeMood = 0.25;
public:
	AMyGameCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;
	
	UFUNCTION(BlueprintCallable)
		void EncenderLinterna(bool encender);

protected:
	//Definiendo funciones para mover al Actor/Objeto(jugador)
	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input(Funcion para mover al jugador hacia adelante) */
	void MoveForward(float Value);

	/** Called for side to side input (Funcion para mover al jugador hacia la derecha)*/
	void MoveRight(float Value);

	bool EnableTouchscreenMovement(UInputComponent * PlayerInputComponent);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins(Funcion para cuando el usurio apreta una tecla). */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops.(Funcion de parada para cuando no hay interacion con el teclado) */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
	void BeginPlay() override;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

