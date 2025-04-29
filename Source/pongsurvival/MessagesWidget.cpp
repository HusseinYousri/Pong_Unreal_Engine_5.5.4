// Fill out your copyright notice in the Description page of Project Settings.


#include "MessagesWidget.h"


void UMessagesWidget::PlayGameOverAnimation()
{
    if (!GameOverAnimation) {return;}
    PlayAnimation(GameOverAnimation);
}
