// Copyright longPointer

// -----------------------------------------------------------------------------

#pragma once

// -----------------------------------------------------------------------------

#include "Runtime\Core\Public\CoreMinimal.h"
#include "Runtime\Engine\Classes\GameFramework\Actor.h"

#include "DefaultAActor.generated.h"

// -----------------------------------------------------------------------------

UCLASS()
class ADefaultAActor : public AActor
{
	GENERATED_BODY()

public:
	ADefaultAActor();

	// Begin AActor
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime);
	// ~AActor

private:
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
